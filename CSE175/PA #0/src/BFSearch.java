import java.util.HashSet;

public class BFSearch {

    public int expansionCount;  // counter for counting number of expansion
    public Map graph;   // a map object that provides all map information
    public String initialLoc;   // start point
    public String destinationLoc;   // final destination
    public int limit;   // number of search limit

    // constructor
    public BFSearch (Map graph, String initialLoc, String destinationLoc, int limit) {
        // initializing...
        this.graph = graph; // encode the map and ready to be searched
        this.initialLoc = initialLoc;   //  name of the start point
        this.destinationLoc = destinationLoc;   // name of the final destination
        this.limit = limit; // depth limit for the search, if expansionCount reach the limit return null
    }

    // Breadth-first search (Queue, FIFO)
    // This search function uses Breadth-first algorithm to find the path from start point to final destination
    // The argument true_or_false is used to check whether the function should use repeated state check or not
    public Waypoint search (boolean true_or_false) {
        Waypoint node = new Waypoint(graph.findLocation(initialLoc));   // set start point as parent node
        expansionCount = 0; // no expansion happen so far

        if (node.loc.name == destinationLoc){
            return node;    // return parent node if initialLoc and destinationLoc are the same
        } else {
            Frontier frontier = new Frontier(); // create a frontier to store current node's child nodes
            frontier.addToBottom(node); // add parent node to frontier first

            // BFS with repeated state check
            if (true_or_false == true) {
                HashSet<String> explored = new HashSet<>();    // create a HashSet to store nodes for repeat state check
                while (!frontier.isEmpty() && node.depth < limit - 1) {
                    node = frontier.removeTop();    // return and remove the very first node in the frontier (FIFO)

                    if (node.isFinalDestination(destinationLoc)) {
                        return node;    // return node when it is the final destination
                    } else {
                        explored.add(node.loc.name);    // add current node to explored for state check
                        node.expand();  // find all children nodes of current node
                        expansionCount++;   // expansion happens so add 1 to expansionCount

                        for (Waypoint i : node.options) {   // for each i in options
                            if (!explored.contains(i.loc.name) && !frontier.contains(i)) {  // state check
                                frontier.addToBottom(i);    // add new node into frontier
                            }
                        }
                    }
                }
                return null;    // failure when frontier is empty or reach to the limit
            } else {
                // BFS without repeated state check
                while (!frontier.isEmpty() && node.depth < limit - 1) {
                    node = frontier.removeTop();    // return and remove the very first node in the frontier (FIFO)
                    if (node.isFinalDestination(destinationLoc)) {
                        return node;    // return node when it is the final destination
                    } else {
                        node.expand(); // find all children nodes of current node
                        expansionCount++;   // expansion happens so add 1 to expansionCount
                        frontier.addToBottom(node.options); // add all children nodes of current node to frontier
                    }
                }
                return null;    // failure when frontier is empty or reach to the limit
            }
        }
    }
}
