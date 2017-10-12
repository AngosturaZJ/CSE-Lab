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
        expansionCount = 0;

        if (node.isFinalDestination(destinationLoc)) {
            return node;
        } else {
            SortedFrontier sortedFrontier = new SortedFrontier(SortBy.g);
            sortedFrontier.addSorted(node);

            if (repeatedChecking) {
                HashSet<String> explored = new HashSet<>();
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();

                    if (node.isFinalDestination(destinationLoc)) {
                        return node;
                    } else {
                        Waypoint checkNode;
                        explored.add(node.loc.name);
                        node.expand();
                        expansionCount++;

                        for (Waypoint option : node.options) {
                            if (!explored.contains(option.loc.name)) {
                                if ((checkNode = sortedFrontier.find(option)) != null) {
                                    if (option.partialPathCost < checkNode.partialPathCost) {
                                        sortedFrontier.remove(checkNode);
                                        sortedFrontier.addSorted(option);
                                    }
                                } else {
                                    sortedFrontier.addSorted(option);
                                }
                            }
                        }
                    }
                }
                return null;
            } else {
                while (!sortedFrontier.isEmpty() && node.depth < limit) {
                    node = sortedFrontier.removeTop();

                    if (node.isFinalDestination(destinationLoc)) {
                        return node;
                    } else {
                        node.expand();
                        expansionCount++;

                        sortedFrontier.addSorted(node.options);
                    }
                }
                return null;
            }
        }
    }
}
