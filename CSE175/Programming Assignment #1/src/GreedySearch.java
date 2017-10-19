import java.util.HashSet;

public class GreedySearch {
    // initializing...
    public Map graph;
    public String initialLoc = " ";
    public String destinationLoc = " ";
    public int limit = 0;
    public int expansionCount = 0;

    // constructor
    GreedySearch(Map graph, String initialLoc, String destinationLoc, int limit) {
        this.graph = graph; // encode map
        this.initialLoc = initialLoc;   // set start point
        this.destinationLoc = destinationLoc;   // set end point
        this.limit = limit; // set search limit
    }

    // the following function uses Greedy Search to find path from the initialLoc and destinationLoc
    // Greedy Search visits each node base on the heuristic value
    // if repeatedChecking is true, the function will use repeated state checking; whereas, the function will not use
    // repeated if repeatedChecking is false
    public Waypoint search(boolean repeatedChecking) {
        Waypoint node = new Waypoint(graph.findLocation(initialLoc), null); //create the initial node
        expansionCount = 0; // initialize the expansionCount

        if (node.isFinalDestination(destinationLoc)) {  // check if the start point is the destination
            return node;    // if start point is the destination, return initial node
        } else {
            // create a sortedFrontier that takes in the current node
            // this sortedFrontier stores nodes and sort them according to every node's heuristic value
            SortedFrontier sortedFrontier = new SortedFrontier(SortBy.h);

            sortedFrontier.addSorted(node); // add the current node to sortedFrontier

            // create a Location object, called endpoint, for generating heuristic function
            Location endpoint = graph.findLocation(destinationLoc);

            GoodHeuristic h = new GoodHeuristic();  // create a GoodHeuristic object called h
            h.startHeuristic(graph, endpoint);  // generate heuristic function

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
                        explored.add(node.loc.name);    // add current node into checklist

                        // expand() will find all child nodes of current node
                        // expand() also calculates the heuristic value for every child node
                        node.expand(h);

                        expansionCount++;   // expand operates once, add 1 to expansionCount

                        // for each child node in the list of child node of current node, do following
                        for (Waypoint option : node.options) {
                            // check explored and sortedFrontier contain the child node or not
                            if (!explored.contains(option.loc.name) && !sortedFrontier.contains(option)) {
                                sortedFrontier.addSorted(option);   // add the child node into sortedFrontier
                            }
                        }
                    }
                }
                return null;    // fail because sortedFrontier is empty or reach the limit
            } else {    // repeated state check is not involved
                // check sortedFrontier is empty or not and check the search limit
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();  // store the first node of sortedFrontier to node

                    if (node.isFinalDestination(destinationLoc)) {  // check the current node is destination or not
                        return node;    // return current node if it is the destination
                    } else {    // do following if current node is not destination

                        // expand(h) will find all child nodes of current node
                        // expand(h) also calculates the heuristic value for every child node
                        node.expand(h);

                        expansionCount++;// expand operates once, add 1 to expansionCount

                        // add the whole list of child nodes into sortedFrontier without repeated state check
                        sortedFrontier.addSorted(node.options);
                    }
                }
                return null;    // fail because sortedFrontier is empty or reach the limit
            }
        }
    }
}
