/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	GraphADT.C
 *
 *  Purpose:	Implementation of GraphADT using Adjacency Lists
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

#include "../include/GraphADT.h"
#include "../include/NodeType.h"
#include "../include/WeightType.h"

/******************************************************************************
   Init : Function to initialize the graph
   inputs : numVertices - Number of Vertices
   outputs : No Outputs
******************************************************************************/
void Graph::Init(int numVertices){
    numVertex = numVertices;
    numEdge = 0;

    // Init Adjacency List
    adj = new struct AdjList[numVertex];
    for(int i=0; i<numVertex; i++){
        adj[i].head = NULL;
    }
}

/******************************************************************************
   getVertices : Returns the number of vertices in the graph
   inputs : No Inputs
   outputs : Number of Vertices in Graph
******************************************************************************/
int Graph::getVertices(){
    return numVertex;
}

/******************************************************************************
   getEdges : Returns the number of edges in the graph
   inputs : No Inputs
   outputs : Number of Edges in Graph
******************************************************************************/
int Graph::getEdges(){
    return numEdge;
}

/******************************************************************************
   first : Returns the first node with v as source
   inputs : v - Source Vertex
   outputs : Pointer to the first node with v as source
******************************************************************************/
NodeType Graph::first(NodeType v){
    // If list is empty, return numVertex
    if (adj[v].head == NULL)
        return numVertex;
    // Return the first node
    return (adj[v].head)->node;
}

/******************************************************************************
   next : Returns the node next to w whose source is v
   inputs : v - Source Vertex
            w - Node whose next node we need
   outputs : Pointer to the node next to w whose source is v
******************************************************************************/
NodeType Graph::next(NodeType v, NodeType w){
    AdjNode *temp = adj[v].head;                /* Temp Pointer to the first node with v as source */

    // Loop to find the node with w as source and return the next node
    while(temp != NULL && temp->next != NULL){
        if(temp->node == w){
            return (temp->next)->node;
        }
        temp = temp->next;
    }
    // If the node is not found return numVertex
    return numVertex;
}

/******************************************************************************
   setEdge : Sets the weight as wt for the edge between v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
            wt - Weight of the edge
   outputs : No Outputs
******************************************************************************/
void Graph::setEdge(NodeType v1, NodeType v2, WeightType wt){
    // If v1 and v2 are same, dont add edge
    if(v1 == v2)
        return;

    AdjNode *temp = new AdjNode;                /* Pointer to the new AdjNode to be added to v1 */

    // Set node and weight
    temp->node = v2;
    temp->weight = wt;
    temp->next = adj[v1].head;

    // Add new node to head of adj list of v1
    adj[v1].head = temp;

    // Increment no of edges
    numEdge++;
}

/******************************************************************************
   delEdge : Removes the edge between v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
   outputs : No Outputs
******************************************************************************/
void Graph::delEdge(NodeType v1, NodeType v2){
    AdjNode *temp = adj[v1].head;               /* Temp Pointer to current AdjNode */
    AdjNode *prev = NULL;                       /* Temp Pointer to previous AdjNode */

    // Loop to find the v2 node in Adj List of v1
    while(temp != NULL){
        if(temp->node == v2){
            // If node is found at head of list, replace the head
            if(prev == NULL){
                adj[v1].head = temp->next;
            }
            // If node is found, replace next of prev node
            else{
                prev->next = temp->next;
            }
            numEdge--;
            return;
        }

        // Goto next node in list
        prev = temp;
        temp = temp->next;
    }
}

/******************************************************************************
   isEdge : Returns true if there exists an edge between v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
   outputs : Whether there exists an edge between v1 and v2
******************************************************************************/
bool Graph::isEdge(NodeType v1, NodeType v2){
    AdjNode *temp = adj[v1].head;               /* Temp Pointer to current AdjNode */

    // Loop to find the v2 node in Adj List of v1
    while(temp != NULL){
        // If v2 is found return true
        if(temp->node == v2){
            return true;
        }

        // Got next node in list
        temp = temp->next;
    }

    // return false if node is not found
    return false;
}

/******************************************************************************
   weight : Returns the weight of the edge connecting v1 and v2
   inputs : v1 - Vertex 1
            v2 - Vertex 2
   outputs : Weight of the edge connecting v1 and v2
******************************************************************************/
WeightType Graph::weight(NodeType v1, NodeType v2){
    AdjNode *temp = adj[v1].head;               /* Temp Pointer to current AdjNode */

    // Loop to find the v2 node in Adj List of v1
    while(temp != NULL){
        // If v2 is found return weight
        if(temp->node == v2){
            return temp->weight;
        }

        // Goto next node in list
        temp = temp->next;
    }

    // return numVertex if node is not found
    return INT_MAX;
}

/******************************************************************************
   getList : Returns the adjacency list header
   inputs : v - Vertex
   outputs : Pointer to the adjacency list header
******************************************************************************/
struct AdjNode* Graph::getList(NodeType v){
    return adj[v].head;
}

/**************************************************************************
 * $Log$
 *
 * End:
 *                        End of GraphADT.C
 **************************************************************************/