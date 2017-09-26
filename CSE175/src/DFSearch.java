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

        Waypoint node = new Waypoint(graph.findLocation(initialLoc));   // set start point as parent node
        expansionCount = 0; // no expansion happen so far

        if (node.loc.name == destinationLoc){
            return node;    // return parent node if initialLoc and destinationLoc are the same
        } else {
            Frontier frontier = new Frontier(); // create a frontier to store nodes
            frontier.addToBottom(node);

            // BFS with repeated state check
            if (true_or_false == true) {
                HashSet<String> explored = new HashSet<>();    // create a HashSet to store nodes for repeat state check
                while (!frontier.isEmpty() && node.depth < limit - 1) {
                    node = frontier.removeTop();

                    if (node.isFinalDestination(destinationLoc)) {
                        return node;
                    } else {
                        explored.add(node.loc.name);
                        node.expand();
                        expansionCount++;

                        for (Waypoint i : node.options) {
                            if (!explored.contains(i.loc.name) && !frontier.contains(i)) {
                                frontier.addToTop(i);
                            }
                        }
                    }
                }
                return null;
            } else {
                while (!frontier.isEmpty() && node.depth < limit - 1) {
                    node = frontier.removeTop();
                    if (node.loc.name == destinationLoc) {
                        return node;
                    } else {
                        node.expand();;
                        expansionCount++;
                        frontier.addToTop(node.options);
                    }
                }
                return null;
            }
        }
    }
}
