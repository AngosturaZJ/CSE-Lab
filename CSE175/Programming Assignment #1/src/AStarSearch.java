public class AStarSearch {
    Map graph;
    String initialLoc;
    String destinationLoc;
    int limit;

    AStarSearch (Map graph, String initialLoc, String destinationLoc, int limit){
        this.graph = graph;
        this.initialLoc = initialLoc;
        this.destinationLoc = destinationLoc;
        this.limit = limit;
    }
}
