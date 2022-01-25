/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	AdjacencyMatrix.h
 *
 *  Purpose:	Header file for implementation of Adjacency Matrix
 *
 *  Author:	CS21M037, N Kausik
 *
 *  Created:    11-10-2021
 *
 *  Last modified:  11-10-2021
 *
 *  Bugs:	-
 *
 **************************************************************************/

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H
#include <iostream>

#include "ElementType.h"

using namespace std;

class AdjacencyMatrix {
  elementType *vertices;
  int **adjMatrix;
  int numVertices;

  public:
    AdjacencyMatrix(){
      vertices = NULL;
      adjMatrix = NULL;
      numVertices = 0;
    }

    AdjacencyMatrix(elementType *vertices, int **adjMatrix, int numVertices){
      this->vertices = vertices;
      this->adjMatrix = adjMatrix;
      this->numVertices = numVertices;
    }

    void createAdjacencyMatrix(elementType *vertices, int **adjMatrix, int numVertices);
    void printAdjacencyMatrix();

};
#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of AdjacencyMatrix.h
 **************************************************************************/