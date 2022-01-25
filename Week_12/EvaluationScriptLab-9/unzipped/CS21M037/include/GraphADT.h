/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	GraphADT.h
 *
 *  Purpose:	Header file for implementation of Graph ADT
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

#ifndef GRAPH_ADT_H
#define GRAPH_ADT_H

#include <iostream>
#include <climits>

#include "../include/NodeType.h"
#include "../include/WeightType.h"

using namespace std;

/*-------------------------------------------------------------------------
 *  AdjNode: Data type for one node of adj list
 -------------------------------------------------------------------------*/
struct AdjNode {
    NodeType node;
    WeightType weight;
    struct AdjNode* next;
};

/*-------------------------------------------------------------------------
 *  AdjList: Data type for adj list
 -------------------------------------------------------------------------*/
struct AdjList{
    struct AdjNode *head;
};

/*-------------------------------------------------------------------------
 *  Graph: Class for representing Graph
 -------------------------------------------------------------------------*/
class Graph{

    int numVertex, numEdge;
    //int *mark;                                             // no of vertices in a graph
    struct AdjList *adj;
    public:
        /* Constructor to initialize the graph */
        Graph(int numVertices){
            Init(numVertices);
        }
        
        /* Function to initialize the graph */
        void Init(int numVertices);
        
        /* Returns the number of vertices in the graph */
        int getVertices();
        
        /* Returns the number of edges in the graph */
        int getEdges();
        
        /* Returns the pointer to the first node with v as source */
        NodeType first(NodeType v);
        
        /* Returns the pointer to the node next to w whose source is v */
        NodeType next(NodeType v, NodeType w);
        
        /* Sets the weight as wt for the edge between v1 and v2 */
        void setEdge(NodeType v1, NodeType v2, WeightType wt);
        
        /* removes the edge between v1 and v2 */
        void delEdge(NodeType v1, NodeType v2);
        
        /* Returns true if there exists an edge between v1 and v2 */
        bool isEdge(NodeType v1, NodeType v2);
        
        /* Returns the weight of the edge connecting v1 and v2 */
        WeightType weight(NodeType v1, NodeType v2);
        
        /* Returns the adjacency list header */
        struct AdjNode* getList(NodeType);
};

#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of GraphADT.h
 **************************************************************************/