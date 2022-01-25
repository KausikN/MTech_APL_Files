/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	DijkstraAlgorithm.h
 *
 *  Purpose:	Header file for Implementation of Dijkstra's Algorithm
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

#ifndef DIJKSTRA_ALGORITHM_H
#define DIJKSTRA_ALGORITHM_H

#include <iostream>
#include <climits>

#include "../include/GraphADT.h"
#include "../include/MinHeap.h"
#include "../include/NodeType.h"
#include "../include/WeightType.h"
using namespace std;

void DijkstraAlgorithm(Graph graph, NodeType source);
#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of DijkstraAlgorithm.h
 **************************************************************************/