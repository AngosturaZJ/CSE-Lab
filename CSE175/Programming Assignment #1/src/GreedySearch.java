public class GreedySearch {
    Map graph;
    String initialLoc;
    String destinationLoc;
    int limit;
    int expansionCount;

    GreedySearch(Map graph, String initialLoc, String destinationLoc, int limit) {
        this.graph = graph;
        this.initialLoc = initialLoc;
        this.destinationLoc = destinationLoc;
        this.limit = limit;
    }
}
