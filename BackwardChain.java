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
    	//Basically, this is a sentence we're breaking down
    	//literals can only match if they have the same predicates
    	if (lit1.pred.equals(lit2.pred))
    	{
    		//since the literals are the same,
    		//these literals will bind if their arguments bind
    		//
    		return unify(lit1.args, lit2.args, bl);
    	}
    	
    	//cannot bind literals that don't have the same predicate
    	return (null);
    }

    // unify -- Return the most general unifier for the two provided terms,
    // or null if no unification is possible.  The returned binding list
    // should be freshly allocated.
    public BindingList unify(Term t1, Term t2, BindingList bl) {
    	//instructions ask for a freshly allocated binding list
    	BindingList bl2 = new BindingList(bl);
    	
    	//This can only be unified if
    	//1) "If term1 and term2 are constants, then term1 and 
    	//term2 unify if and only if they are the same atom, or the same number."
    	if (t1.c != null)
    	{
    		//t1 is a constant
    		if (t2.c != null)
    		{
    			//t2 is a constant
    			if (t1.equals(t2))
    			{
    				//the constants match, so it "binds" (loosely used, since there was no new binding)
    				//we return a "freshly allocated" binding list
    				//using the copy constructor for Binding List
    				//but we don't actually have to add anything since the constants 
    				//are already in there
    				return bl2;
    			}
    			else
    			{
    				//if the constants don't match, then we cannot bind
    				return null;
    			}	
    		} 		//end t1 and t2 is a constant
        	//2) we can bind  a constant to
    		//a variable if it hasn't been bound already
    		//we switch the order of the arguments and call again
    		//so that we don't have to code a billion things here
    		//and it will hit below
    		if (t2.v != null)
    			return unify(t2, t1, bl2);
    		//a constant can only bind to the same constant or
    		//an unbound variable
    		return null;
    	}
	    //end t1 is a constant
	    
	    //2) You can bind a variable to a to any type of term
		// if it hasn't been bound already
		if (t1.v != null)
	    {	
	    	//t1 is a variable
			//check if it is bound
			Term bind = bl.boundValue(t1.v);
	    	if (bind != null)
			{
	    		//t1 bound, so we have to check that binding
	    		//if we want to unify
	    		//switch order and pass again to so we don't have to program as much
	    		return unify(t2, bind, bl2);
			}	//end t1 is bound
	    	
	    	//3)	Unbound variables bind to a constant by adding a binding
	    	if (t2.c != null)
	    	{
	    		//t2 is a constant, just add a binding
	    		bl2.addBinding(t1.v, t2);
	    		return bl2;
	    	}
	    	
	    	//4)	Unbound variables can bind to another variable
	    	//		or we check the reverse case where t1 isn't bound but t2 is
	    	//		Or if the two variables are the same, the kb doesn't change
	    	if (t2.v != null)
	    	{
	    		if (t1.v.equals(t2.v))
	    		{
	    			//the two variables are the same
	    			//no new bindings needed to unify
	    			return bl2;
	    		}	//end variables are the same
	    		//check if t2 is bound
	    		Term bind2 = bl.boundValue(t2.v);
	    		if (bind2 != null)
	    		{
	    			return unify(t1, bind2, bl2);
	    		}
	    		else
	    		{
	    			//neither variable is bound, so we unify them by adding a binding
	    			//could be bound either as t2.v, t1, or what we did. It's just convention
	    			bl2.addBinding(t1.v, t2);
	    			return bl2;
	    		}		
	    	}//end t2 is a variable
	    	
	    	//5) last option for t1 == variable is if t2 is a function
	    	//We can unify this easily, however, we should do an occur check
	    	//to make sure the variable doesn't already show up in the function
	    	//e.g. father of yourself problem
	    	if (t2.f != null)
			{
				if (((t2.f.subst(bl2)).allVariables()).contains(t1.v))
				{
					//here's the occur check (check all variables in the function
					//for containing our variable). If this is ever true
					//it occurs, and we can't unify
					return null;
				}
				//since our variable didn't occur in our function, we can bind
				//the variable to the function and unify the statements
				bl2.addBinding(t1.v, t2);
				return bl2;
			}
	    	
	    	//Last option is if t1 is a function
	    	//functions can only bind with variables and other functions
	    	if (t1.f != null)
	    	{
	    		if (t2.c != null)
	    		{
	    			//t2 is a constant, and you can't bind a function to a constant
	    			return null;
	    		}
	    		if (t2.v != null)
	    		{
	    			//t2 is a variable. We just wrote this up above, so let's send it back there
	    			//by changing the order of the arguments. If we didn't flip the order
	    			//we would infinite loop like idiots ^ ^
	    			return unify(t2, t1, bl2);
	    		}
	    		if (t2.f != null)
	    		{
	    			//t2 is a function. We wrote this below, so we're just going to send it there.
	    			return unify(t1.f, t2.f, bl2);
	    		}
	    	}
		}
		
		//The only way we get here is if t1 is a Term without a .c, .v, or .f
		//Which means it's probably uninitialized, so the arguments make no sense.
    	return (null);
    }
    	
    

    // unify -- Return the most general unifier for the two provided lists of
    // terms, or null if no unification is possible.  The returned binding list
    // should be freshly allocated.
    public BindingList unify(Function f1, Function f2, BindingList bl) {
	
		if (f1.func.equals(f2.func))
			return unify(f1.args, f2.args, bl);
		return (null);
    }

    // unify -- Return the most general unifier for the two provided lists of
    // terms, or null if no unification is possible.  The returned binding 
    // list should be freshly allocated.
    public BindingList unify(List<Term> ts1, List<Term> ts2, 
			     BindingList bl) {
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

