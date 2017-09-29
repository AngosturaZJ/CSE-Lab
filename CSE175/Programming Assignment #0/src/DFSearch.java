import java.util.HashSet;

public class DFSearch {

    public int expansionCount;
    public Map graph;
    public String initialLoc;
    public String destinationLoc;
    public int limit;

    //constructor
    public DFSearch(Map graph, String initialLoc, String destinationLoc, int limit){
        // initializing...
        this.graph = graph;
        this.initialLoc = initialLoc;
        this.destinationLoc = destinationLoc;
        this.limit = limit;
    }

    // Depth-first search (Stack, FILO)
    public Waypoint search(boolean true_or_false) {

        Waypoint node = new Waypoint(graph.findLocation(initialLoc));   // set start point as parent node
        expansionCount = 0; // no expansion happen so far

        if (node.loc.name == destinationLoc){
            return node;    // return parent node if initialLoc and destinationLoc are the same
        } else {
            Frontier frontier = new Frontier(); // create a frontier to store nodes
            frontier.addToBottom(node); // add parent node to the frontier

            // BFS with repeated state check
            if (true_or_false == true) {
                HashSet<String> explored = new HashSet<>();    // create a HashSet to store nodes for repeat state check
                while (!frontier.isEmpty() && node.depth < limit - 1) {
                    node = frontier.removeTop();    // return and remove the very top node in the frontier (FILO)

                    if (node.isFinalDestination(destinationLoc)) {
                        return node;    // return node when it is the final destination
                    } else {
                        explored.add(node.loc.name);    // add current node to explored for state check
                        node.expand();  // find all children nodes of current node
                        expansionCount++;   // expansion happens so add 1 to expansionCount

                        for (Waypoint i : node.options) {
                            if (!explored.contains(i.loc.name) && !frontier.contains(i)) {  // state check
                                frontier.addToTop(i);   // add new node into frontier
                            }
                        }
                    }
                }
                return null;    // failure when frontier is empty or reach to the limit
            } else {
                // BFS without repeated state check
                while (!frontier.isEmpty() && node.depth < limit - 1) {
                    node = frontier.removeTop();    // return and remove the very top node in the frontier (FILO)
                    if (node.loc.name == destinationLoc) {
                        return node;    // return node when it is the final destination
                    } else {
                        node.expand();  // find all children nodes of current node
                        expansionCount++;   // expansion happens so add 1 to expansionCount
                        frontier.addToTop(node.options);    // add all children node of current node to frontier
                    }
                }
                return null;    // failure when frontier is empty or reach to the limit
            }
        }
    }
}
