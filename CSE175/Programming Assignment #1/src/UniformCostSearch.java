import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

public class UniformCostSearch {
	// initializing...
    public Map graph;
    public String initialLoc = " ";
    public String destinationLoc = "";
    public int limit = 0;
    public int expansionCount = 0;

    // constructor
    public UniformCostSearch(Map graph, String initialLoc, String destinationLoc, int limit) {
        this.graph = graph;	// encode map as object graph
        this.initialLoc = initialLoc;	// set start point
        this.destinationLoc = destinationLoc; // set end point
        this.limit = limit;	//set search limit
    }
    
    // the following function uses Uniform Cost Search to find path from the initialLoc to destinationLoc
    // Uniform Cost Search always visit the node that has less partialPathCost first
    // if repeatedChecking is true, the function will use repeated state checking; whereas, the function will not use
    // repeated if repeatedChecking is false
    public Waypoint search(boolean repeatedChecking) {
        Waypoint node = new Waypoint(graph.findLocation(initialLoc), null);	//create the initial node
        expansionCount = 0;	// initialize the expansionCount

        if (node.isFinalDestination(destinationLoc)) {	// check if the start point is the destination
            return node;	// if start point is the destination, return initial node
        } else {
        	// create a sortedFrontier that takes in the current node
        	// this sortedFrontier stores nodes and sort them according to every node's partialPathCost value
            SortedFrontier sortedFrontier = new SortedFrontier(SortBy.g);
            sortedFrontier.addSorted(node);	// add current node into sortedFrontier

            if (repeatedChecking) {	// repeated state check involves
                Set<String> explored = new HashSet<>();	// create a hashset, called explored, that store visted node
                // check sortedFrontier is empty or not and check the search limit
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();	// store the first node of sortedFrontier to node

                    if (node.isFinalDestination(destinationLoc)) {	// check the current node is destination or not
                        return node;	// return current node if it is the destination
                    } else {	// do following if current node is not destination
                        Waypoint checkNode;	// create a new node for storing node
                        explored.add(node.loc.name);	// add current node into checklist
                        node.expand();	// find all child nodes of current node
                        expansionCount++;	// expand operates once so add 1 to expansionCount

                        // for each child node in the list of child node of current node, do following
                        for (Waypoint option : node.options) {
                            // if the child node is not in explored, do following
                            if (!explored.contains(option.loc.name)) {
                                // if the child node has already added in sortedFrontier before, do following
                                if (sortedFrontier.contains(option) == true) {
                                    // store the old version child node into checkNode for comparing partialPathCost with
                                    // the new version node
                                    checkNode = sortedFrontier.find(option);
                                    // if the child node's partialPathCost is less than its old version's
                                    if (option.partialPathCost < checkNode.partialPathCost) {
                                        // delete old version child node from sortedFrontier
                                        sortedFrontier.remove(checkNode);
                                        // add the child node, which has less partialPathCost, into sortedFrontier
                                        sortedFrontier.addSorted(option);
                                    }
                                } else {	// if the child node never add to sortedFrontier before
                                    sortedFrontier.addSorted(option);	// add the child node to sortedFrontier directly
                                }
                            }
                        }
                    }
                }
                return null;	// fail if sortedFrontier is empty or reach to the limit
            } else {	// operate search function without repeated state check
            	// check sortedFrontier is empty or not and check the search limit
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();	// check the current node is destination or not

                    if (node.isFinalDestination(destinationLoc)) {	// check the current node is destination or not
                        return node;	// return current node if it is the destination
                    } else {	// do following if current node is not destination
                        node.expand();	// find all child nodes of current node
                        expansionCount++;	// expand operates once so add 1 to expansionCount

                        sortedFrontier.addSorted(node.options);	// no repeated state checking involved, add the list of child node of current node directly into sortedFrontier
                    }
                }
                return null;	// fail if sortedFrontier is empty or reach to the limit
            }
        }
    }
}
