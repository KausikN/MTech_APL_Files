/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	AdjacencyMatrix.C
 *
 *  Purpose:	Implementation of Adjacency Matrix
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
#include "../include/AdjacencyMatrix.h"
#include "../include/ElementType.h"

using namespace std;

void AdjacencyMatrix::createAdjacencyMatrix(elementType *vertices, int **adjMatrix, int numVertices){
    this->vertices = vertices;
    this->adjMatrix = adjMatrix;
    this->numVertices = numVertices;
}

void AdjacencyMatrix::printAdjacencyMatrix(){
    int i, j;                               /* Loop counters */

    // Print Vertices at Top
    cout << "    " << "\t\t\t";
    for (i = 0; i < numVertices; i++){
        cout << "V" << i << ":" << vertices[i] << "\t\t\t";
    }
    cout << endl;
    
    // Print Adjacency Matrix
    for(i = 0; i < numVertices; i++){
        cout << "V" << i << ":" << vertices[i] << "\t\t\t";
        for(j = 0; j < numVertices; j++){
            cout << adjMatrix[i][j] << "\t\t\t";
        }
        cout << endl;
    }
}


/**************************************************************************
 * $Log$
 *
 * End:
 *                        End of AdjacencyMatrix.C
 **************************************************************************/