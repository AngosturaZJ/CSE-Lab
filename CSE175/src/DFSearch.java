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

    // Depth-first search (Queue, FIFO)
    public Waypoint search(boolean true_or_false) {

        expansionCount = 0;
        Waypoint node = new Waypoint(graph.findLocation(initialLoc));   // create a node that contains start point
        Frontier frontier = new Frontier(); // create a frontier to store all children of the node
        frontier.addToTop(node); // store start point into frontier

        // BFS with state checking
        if (true_or_false == true) {
            // create HashSet to store every node that has been explored
            HashSet<String> state_check = new HashSet<>();

            while (!frontier.isEmpty() && node.depth < limit - 1) {
                node = frontier.removeTop();
                if (node.isFinalDestination(destinationLoc)) {
                    return node;
                } else {
                    state_check.add(node.loc.name);
                    node.expand();
                    expansionCount++;
                    for (Waypoint i : node.options) {
                        if (!frontier.contains(i.loc.name) && !state_check.contains(i.loc.name)) {
                            frontier.addToTop(i);
                        }
                    }
                }
            }
            return null;
        } else {
            while (!frontier.isEmpty() && node.depth < limit - 1) {
                node = frontier.removeTop();
                if (node.isFinalDestination(destinationLoc)) {
                    return node;
                } else {
                    node.expand();
                    expansionCount++;
                    frontier.addToTop(node.options);
                }
            }
            return null;
        }
    }
}
