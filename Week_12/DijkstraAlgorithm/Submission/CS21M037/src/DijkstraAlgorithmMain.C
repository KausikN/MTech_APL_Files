/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	DijkstraAlgorithmMain.C
 *
 *  Purpose:	Main for performing Dijkstra's Algorithm using Graph ADT and MinHeap
 *
 *  Author:	CS21M037, N Kausik
 *
 *  Created:    01-11-2021
 *
 *  Last modified:  
 *
 *  Bugs:	
 *
 *  Change Log:	
 *  
 *
 **************************************************************************/

#include <iostream>
#include <climits>

#include "../include/DijkstraAlgorithm.h"
#include "../include/GraphADT.h"
#include "../include/MinHeap.h"
#include "../include/NodeType.h"
#include "../include/WeightType.h"

using namespace std;

/******************************************************************************
   main : Main function to run the program
   inputs : No Inputs
   outputs : 0 if no errors
******************************************************************************/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int     numVertices;                        /* No of Vertices */
    int     numEdges;                           /* No of Edges */

    // Get Number of Vertices and Edges
    cin >> numVertices;
    cin >> numEdges;

    // Init Graph
    Graph   graph = Graph(numVertices);

    // Get Edges
    int     i;                                  /* Iterator Variable */
    for (i=0; i<numEdges; i++) {
        int u, v, weight;
        cin >> u;
        cin >> v;
        cin >> weight;

        // Add Edge to Groph
        graph.setEdge(u, v, weight);
        graph.setEdge(v, u, weight);
    }

    // Run Dijkstra Algorithm
    int     source = 0;                         /* Source Vertex as 0 */
    DijkstraAlgorithm(graph, source);

    return 0;
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of DijkstraAlgorithmMain.C
 **************************************************************************/