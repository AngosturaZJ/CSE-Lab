import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;

public class UniformCostSearch {

    public Map graph;
    public String initialLoc;
    public String destinationLoc;
    public int limit;
    public int expansionCount;

    public UniformCostSearch(Map graph, String initialLoc, String destinationLoc, int limit) {
        this.graph = graph;
        this.initialLoc = initialLoc;
        this.destinationLoc = destinationLoc;
        this.limit = limit;
    }

    public Waypoint search(boolean repeatedChecking) {
        Waypoint node = new Waypoint(graph.findLocation(initialLoc), null);
        SortedFrontier sortedFrontier = new SortedFrontier(SortBy.g);
        sortedFrontier.addSorted(node);
        expansionCount = 0;

        while (!sortedFrontier.isEmpty() && node.depth < limit) {
            node = sortedFrontier.removeTop();
            if (node.isFinalDestination(destinationLoc)) {
                return node;
            } else {
                node.expand();
                expansionCount++;

                if (repeatedChecking) {
                    Waypoint checkNode;
                    HashSet<String> explored = new HashSet<String>();
                    explored.add(node.loc.name);

                    for (Waypoint option : node.options) {
                        if (!explored.contains(option.loc.name)) {
                            if ((checkNode=sortedFrontier.find(option)) != null) {
                                if (option.partialPathCost < checkNode.partialPathCost) {
                                    sortedFrontier.remove(checkNode);
                                    sortedFrontier.addSorted(option);
                                }
                            } else {
                                sortedFrontier.addSorted(option);
                            }
                        }
                    }
                } else {
                    sortedFrontier.addSorted(node.options);
                }
            }

        }
        return null;

    }
}
