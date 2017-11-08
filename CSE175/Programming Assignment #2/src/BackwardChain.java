//
// BackwardChain
//
// This class implements a backward chaining inference procedure.  The
// implementation is very skeletal, and the resulting reasoning process is
// not particularly efficient.  Knowledge is restricted to the form of
// definite clauses, grouped into a list of positive literals (facts) and
// a list of Horn clause implications (rules).  The inference procedure
// maintains a list of goals.  On each step, a proof is sought for the
// first goal in this list, starting by an attempt to unify the goal with
// any known fact in the knowledge base.  If this fails, the rules are
// examined in the order in which they appear in the knowledge base, searching
// for a consequent that unifies with the goal.  Upon successful unification,
// a proof is sought for the conjunction of the rule antecedents.  If this
// fails, further rules are considered.  Note that this is a strictly
// depth-first approach, so it is incomplete.  Note, also, that there is
// no backtracking with regard to matches to facts -- the first match is
// always taken and other potential matches are ignored.  This can make
// the algorithm incomplete in another way.  In short, the order in which
// facts and rules appear in the knowledge base can have a large influence
// on the behavior of this inference procedure.
//
// In order to use this inference engine, the knowledge base must be
// initialized by a call to "initKB".  Queries are then submitted using the
// "ask" method.  The "ask" function returns a binding list which includes
// bindings for intermediate variables.
//
// David Noelle -- Tue Apr 10 17:08:45 PDT 2007
//


import java.util.*;


public class BackwardChain {

    public KnowledgeBase kb;

    // Default constructor ...
    public BackwardChain() {
		this.kb = new KnowledgeBase();
    }

    // initKB -- Initialize the knowledge base by interactively requesting
    // file names and reading those files.  Return false on error.
    public boolean initKB() {
        return (kb.readKB());
    }

    // unify -- Return the most general unifier for the two provided literals,
    // or null if no unification is possible.  The returned binding list
    // should be freshly allocated.
    public BindingList unify(Literal lit1, Literal lit2, BindingList bl) {
	
		// PROVIDE YOUR CODE HERE!
        // check whether both literals are the same
        // literals can only match when they have the exact same predicate
    	if (lit1.pred.equals(lit2.pred)) {
    	    // when both literals are matched, they will bind
    		return unify(lit1.args, lit2.args, bl);
    	}
		return (null);
    }

    // unify -- Return the most general unifier for the two provided terms,
    // or null if no unification is possible.  The returned binding list
    // should be freshly allocated.
    public BindingList unify(Term t1, Term t2, BindingList bl) {
	
		// PROVIDE YOUR CODE HERE!
        // create a new BindingList for freshly allocated
    	BindingList new_bl = new BindingList(bl);
    	// CASE 1, t1 and t2 are both constant
    	if (t1.c != null) {                   // check for whether t1 is constant or not
    		if (t2.c != null) {               // check for whether t2 is constant or not
    			if (t1.equals(t2)) {          // t1 and t2 are exactly the same thing
                    // t1 and t2 matched, so they will bind
                    // although we don't need modify binding list, in order to return freshly allocated
                    // binding list, we have to return new binding list, called new_bl
					return new_bl;
				}
    		}
    		if (t2.v != null) {               // when t2 is variable
                // when one term is constant and another is variable, constant can be bind into variable
    			return unify(t2, t1, new_bl);
    		}
    	}
    	// CASE 1 done
    	
    	// CASE 2, t1 is variable
    	if (t1.v != null) {
    	    // create a new Term object, called bind1, it is used to check whether t1 is bound or not
    		Term bind1 = bl.boundValue(t1.v);
    		if (bind1 != null) {     // when t1 is bound
    			return unify(t2, bind1, new_bl);
    		}
    		// when t2 is constant
    		if (t2.c != null) {
    		    // in order to bind unbound variable to constant, we have to add binding
    			new_bl.addBinding(t1.v, t2);
    			return new_bl;      // return the new binding list
    		}
    		// when t2 is variable
    		if (t2.v != null) {
    		    // when t1 and t2 are both unbound variables, we do not need modify anything
    			if (t1.v.equals(t2.v)) {
    				return new_bl;      // return new_bl for freshly allocated
    			}
    			// create a new Term object, call Bind, for checking whether t2 is bound or not
    			Term bind2 = bl.boundValue(t2.v);
    			if (bind2 != null) {        // when t2 is bound
    				return unify(t1, bind2, new_bl);
    			} else {
    			    // when both terms are not bound, we can add binding to unify them
    				new_bl.addBinding(t2.v, t1);
    				return new_bl;
    			}
    		}
    	}
    	// CASE 2 done
    	
    	// CASE 3, t1 is function
    	if (t1.f != null) {
    		if (t2.v != null) {     // when t2 is variable
                // change the order of t1 and t2 to avoid infinite loop
    			return unify(t2, t1, new_bl);
    		}
    		if (t2.f != null) {     // when t2 is function
    			return unify(t1.f, t2.f, new_bl);
    		}
    	}
    	// CASE 3 done
        // in the case of t1 is function and t2 is constant, this method will return null
		return (null);
    }

    // unify -- Return the most general unifier for the two provided lists of
    // terms, or null if no unification is possible.  The returned binding list
    // should be freshly allocated.
    public BindingList unify(Function f1, Function f2, BindingList bl) {
	
		// PROVIDE YOUR CODE HERE!
        // this method is called when both terms are function
    	if (f1.func.equals(f2.func)) {
    		return unify(f1.args, f2.args, bl);
    	}
		return (null);
    }

    // unify -- Return the most general unifier for the two provided lists of
    // terms, or null if no unification is possible.  The returned binding 
    // list should be freshly allocated.
    public BindingList unify(List<Term> ts1, List<Term> ts2, BindingList bl) {
		if (bl == null)
	    	return (null);
		if ((ts1.size() == 0) && (ts2.size() == 0))
	    	// Empty lists match other empty lists ...
	    	return (new BindingList(bl));
		if ((ts1.size() == 0) || (ts2.size() == 0))
	    	// Ran out of arguments in one list before reaching the
	    	// end of the other list, which means the two argument lists
	    	// can't match ...
	    	return (null);
		List<Term> terms1 = new LinkedList<Term>();
		List<Term> terms2 = new LinkedList<Term>();
		terms1.addAll(ts1);
		terms2.addAll(ts2);
		Term t1 = terms1.get(0);
		Term t2 = terms2.get(0);
		terms1.remove(0);
		terms2.remove(0);
		return (unify(terms1, terms2, unify(t1, t2, bl)));
    }

    // askFacts -- Examine all of the facts in the knowledge base to
    // determine if any of them unify with the given literal, under the
    // given binding list.  If a unification is found, return the
    // corresponding most general unifier.  If none is found, return null
    // to indicate failure.
    BindingList askFacts(Literal lit, BindingList bl) {
		BindingList mgu = null;  // Most General Unifier
		for (Literal fact : kb.facts) {
		    mgu = unify(lit, fact, bl);
		    if (mgu != null)
				return (mgu);
		}
		return (null);
    }

    // askFacts -- Examine all of the facts in the knowledge base to
    // determine if any of them unify with the given literal.  If a
    // unification is found, return the corresponding most general unifier.
    // If none is found, return null to indicate failure.
    BindingList askFacts(Literal lit) {
		return (askFacts(lit, new BindingList()));
    }

    // ask -- Try to prove the given goal literal, under the constraints of
    // the given binding list, using both the list of known facts and the 
    // collection of known rules.  Terminate as soon as a proof is found,
    // returning the resulting binding list for that proof.  Return null if
    // no proof can be found.  The returned binding list should be freshly
    // allocated.
    BindingList ask(Literal goal, BindingList bl) {
		BindingList result = askFacts(goal, bl);
		if (result != null) {
		    // The literal can be unified with a known fact ...
		    return (result);
		}
		// Need to look at rules ...
		for (Rule candidateRule : kb.rules) {
		    if (candidateRule.consequent.pred.equals(goal.pred)) {
				// The rule head uses the same predicate as the goal ...
				// Standardize apart ...
				Rule r = candidateRule.standardizeApart();
				// Check to see if the consequent unifies with the goal ...
				result = unify(goal, r.consequent, bl);
				if (result != null) {
			    	// This rule might be part of a proof, if we can prove
					// the rule's antecedents ...
			    	result = ask(r.antecedents, result);
		    		if (result != null) {
					// The antecedents have been proven, so the goal
					// is proven ...
					return (result);
		    		}
				}
	    	}
		}
		// No rule that matches has antecedents that can be proven.  Thus,
		// the search fails ...
		return (null);
    }

    // ask -- Try to prove the given goal literal using both the list of 
    // known facts and the collection of known rules.  Terminate as soon as 
    // a proof is found, returning the resulting binding list for that proof.
    // Return null if no proof can be found.  The returned binding list 
    // should be freshly allocated.
    BindingList ask(Literal goal) {
		return (ask(goal, new BindingList()));
    }

    // ask -- Try to prove the given list of goal literals, under the 
    // constraints of the given binding list, using both the list of known 
    // facts and the collection of known rules.  Terminate as soon as a proof
    // is found, returning the resulting binding list for that proof.  Return
    // null if no proof can be found.  The returned binding list should be
    // freshly allocated.
    BindingList ask(List<Literal> goals, BindingList bl) {
		if (goals.size() == 0) {
		    // All goals have been satisfied ...
		    return (bl);
		} else {
		    List<Literal> newGoals = new LinkedList<Literal>();
		    newGoals.addAll(goals);
	    	Literal goal = newGoals.get(0);
		    newGoals.remove(0);
	    	BindingList firstBL = ask(goal, bl);
	    	if (firstBL == null) {
				// Failure to prove one of the goals ...
				return (null);
		    } else {
			// Try to prove the remaining goals ...
			return (ask(newGoals, firstBL));
	    	}
		}
    }


}

