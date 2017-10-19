import java.util.HashSet;

public class AStarSearch {
    // initializing...
    public Map graph;
    public String initialLoc = " ";
    public String destinationLoc = " ";
    public int limit = 0;
    public int expansionCount = 0;

    // constructor
    AStarSearch(Map graph, String initialLoc, String destinationLoc, int limit){
        this.graph = graph; // encode the map
        this.initialLoc = initialLoc;   // set start point
        this.destinationLoc = destinationLoc;   // set end point
        this.limit = limit; // set search limit
    }

    // the following function uses A* Search to find path from the initialLoc and destinationLoc
    // A* Search will visit each node by evaluating the value of heuristic value and particalPathCost
    // if repeatedChecking is true, the function will use repeated state checking; whereas, the function will not use
    // repeated if repeatedChecking is false
    public Waypoint search(boolean repeatedChecking) {
        Waypoint node = new Waypoint(graph.findLocation(initialLoc), null); //create the initial node
        expansionCount = 0; // initialize the expansionCount

        if (node.isFinalDestination(destinationLoc)) {  // check if the start point is the destination
            return node;    // if start point is the destination, return initial node
        } else {
            // create a sortedFrontier that takes in the current node
            // this sortedFrontier stores nodes
            // sortedFrontier also sorts nodes according to combination of heuristic value and particalPathCost
            SortedFrontier sortedFrontier = new SortedFrontier(SortBy.f);
            sortedFrontier.addSorted(node); // add current node into sortedFrontier

            // create a GoodHeuristic object, called h, for calculating heuristic value and particalPathCost
            GoodHeuristic hc = new GoodHeuristic();
            Location endpoint = graph.findLocation(destinationLoc); // create a Location of endpoint for generate Heuristic
            hc.startHeuristic(graph, endpoint);  // operate Heuristic evaluation

            if (repeatedChecking) { // if repeatedChecking is true, repeated state checking involves
                // create a HashSet, called explored, for repeated checking
                // every visited node will be added in to HashSet
                HashSet<String> explored = new HashSet<>();

                // check sortedFrontier is empty or not and check the search limit
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();  // store the first node of sortedFrontier to node

                    if (node.isFinalDestination(destinationLoc)) {  // check the current node is destination or not
                        return node;    // return current node if it is the destination
                    } else {    // do following if current node is not destination
                        Waypoint checkNode; // create a new node for storing node
                        explored.add(node.loc.name);    // add current node into checklist
                        node.expand(hc); // find all child nodes of current node
                        expansionCount++;   // expand operates once so add 1 to expansionCount

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
                                } else {    // if the child node never add to sortedFrontier before
                                    sortedFrontier.addSorted(option);   // add the child node to sortedFrontier directly
                                }
                            }
                        }
                    }
                }
                return null;    // fail if sortedFrontier is empty or reach to the limit
            } else {    // operate search function without repeated state check
                // check sortedFrontier is empty or not and check the search limit
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();  // check the current node is destination or not

                    if (node.isFinalDestination(destinationLoc)) {  // check the current node is destination or not
                        return node;    // return current node if it is the destination
                    } else {    // do following if current node is not destination
                        // expand(hc) will find all child nodes of current node
                        // expand(hc) also calculates the heuristic value and particalPathCost for every child node
                        node.expand(hc);

                        expansionCount++;   // expand operates once so add 1 to expansionCount

                        // add the whole list of child nodes into sortedFrontier without repeated state check
                        sortedFrontier.addSorted(node.options);
                    }
                }
                return null;    // fail because sortedFrontier is empty or reach the limit
            }
        }
    }
}
