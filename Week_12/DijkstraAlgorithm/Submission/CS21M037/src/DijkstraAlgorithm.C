/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	DijkstraAlgorithm.C
 *
 *  Purpose:	Implementation of Dijkstra's Algorithm
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

/******************************************************************************
   DijkstraAlgorithm : Dijkstra's Algorithm to compute shortest distance between 
                       source and all other vertices
   inputs : graph - Graph object
            source - Source vertex
   outputs : No Outputs
******************************************************************************/
void DijkstraAlgorithm(Graph graph, NodeType source){
    int     numVertices = graph.getVertices();      /* Number of vertices in the graph */

    // Initialise final min heap
    MinHeap finalMinHeap = MinHeap(numVertices);    /* Min Heap to store final distances */

    // Initialise MinHeap with source vertex
    MinHeap minHeap = MinHeap(numVertices);         /* Min Heap to store distances */
    minHeap.insert(source, 0);

    // Add all other vertices to the heap
    for(int i = 0; i < numVertices; i++){
        if(i != source){
            minHeap.insert(i, INT_MAX);
        }
    }

    // Loop until minHeap is empty
    while(!minHeap.isEmpty()){
        // Extract the minimum distance node from minHeap
        // In minHeap minimum distance node is simply the root
        struct MinHeap::HeapNode* minHeapNode = minHeap.deleteRoot();
        NodeType u = minHeapNode->node;

        // Add removed node to final min heap
        finalMinHeap.insert(minHeapNode->node, minHeapNode->dist);

        // If minHeap is at INT_MAX dist, no need to update any distances
        if (minHeapNode->dist == INT_MAX)
            continue;

        // Loop through all adjacent vertices of u
        AdjNode* vNode = graph.getList(u);
        NodeType v = vNode->node;
        while (vNode != NULL){
            v = vNode->node;
            // If v is in minHeap and w is not INT_MAX, Update the distance for v from source
            if(minHeap.inHeap(v)){
                WeightType w = graph.weight(u, v);
                if (w != INT_MAX){
                    WeightType dist = minHeapNode->dist + w;
                    // Update the distance of v from source if it is smaller than the current distance
                    minHeap.decreaseKey(v, dist);
                }
            }

            // Goto next adjacent vertex
            vNode = vNode->next;
        }
    }

    // Print the shortest distance from source to all other vertices
    finalMinHeap.printHeap();
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of DijkstraAlgorithm.C
 **************************************************************************/