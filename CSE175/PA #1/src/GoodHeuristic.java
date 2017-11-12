//
// GoodHeuristic
//
// This class extends the Heuristic class, providing a reasonable
// implementation of the heuristic function method.  The provided "good"
// heuristic function is admissible.
//
// YOUR NAME -- TODAY'S DATE
//


import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GoodHeuristic extends Heuristic {

    // YOU CAN ADD ANYTHING YOU LIKE TO THIS CLASS ... WHATEVER WOULD
    // ASSIST IN THE CALCULATION OF YOUR GOOD HEURISTIC VALUE.

    // heuristicFunction -- Return the appropriate heuristic values for the
    // given search tree node.  Note that the given Waypoint should not be
    // modified within the body of this function.
    public double heuristicFunction(Waypoint wp) {
	    double hVal;
	
	    // COMPUTE A REASONABLE HEURISTIC VALUE HERE

        // heuristic value = distance between start point and end point / highest speed
        hVal = distance(wp.loc, getDestination())/ maxSpeed;
	    return (hVal);
    }

    double maxSpeed = 0.0;  // store in maximum speed

    // this function will find highest speed and set end point
    public void startHeuristic(Map graph, Location endpoint) {
        maxRoadSpeed(graph);    // find maximum speed
        setDestination(endpoint);   // set end point
    }

    // this function will find the distant between two locations
    public double distance(Location startpoint, Location endtopint){
        double lon = startpoint.longitude - endtopint.longitude;
        double lat = startpoint.latitude - endtopint.latitude;

        return Math.sqrt(lon * lon + lat * lat);
    }

    // this function will find the highest speed in the map
    public double maxRoadSpeed(Map graph) {
        double speed;   // store in speed of road for every speed calculation
        for (Location location : graph.locations) { // iterate all locations in the map
            for (Road road : location.roads) {  // iterate all roads that connect to current location
                speed = distance(road.fromLocation, road.toLocation)/road.cost; // find the speed of current road

                // find the highest speed
                if (speed > maxSpeed) {
                    maxSpeed = speed;
                }
            }
        }
        return maxSpeed;
    }


}
