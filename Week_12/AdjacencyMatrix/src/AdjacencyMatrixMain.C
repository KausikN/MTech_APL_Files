/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	AdjacencyMatrixMain.C
 *
 *  Purpose:	Main file for generating a graph using Adjacency Matrix
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

#include <iostream>

#include "../include/ElementType.h"
#include "../include/AdjacencyMatrix.h"

/******************************************************************************
   main : Main function to run the program
   inputs : No Inputs
   outputs : 0 if no errors
******************************************************************************/
int main() {
  AdjacencyMatrix adjMatrix;                              /* Adjacency Matrix Object */
  elementType     *vertices;                              /* Vertices Data */
  int**           adjM;                                   /* Adjacency Matrix Input */
  int             numVertices;                            /* Number of Vertices */
  
  cin >> numVertices;                                     /* Get number of vertices */

  int i = 0;                                              /* Loop variable */
  // Get data for vertices
  vertices = (int*) malloc(numVertices * sizeof(elementType)); /* Allocate Memory for vertices */
  for (i = 0; i < numVertices; i++) {
    cin >> vertices[i];
  }

  // Get distances between vertices
  adjM = (int**) malloc(numVertices * sizeof(int*));      /* Allocate Memory for adjM */
  for (i = 0; i < numVertices; i++) {
    adjM[i] = (int*) malloc(numVertices * sizeof(int));   /* Allocate Memory for adjM[i] */
    for (int j = 0; j < numVertices; j++) {
      cin >> adjM[i][j];
    }
  }

  // Create Adjacency Matrix
  adjMatrix.createAdjacencyMatrix(vertices, adjM, numVertices);

  // Print Adjacency Matrix
  adjMatrix.printAdjacencyMatrix();

  return(0);
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of AdjacencyMatrixMain.C
 **************************************************************************/