/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	MinHeap.h
 *
 *  Purpose:	Header file for implementation of Min Heap
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

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <climits>

#include "../include/NodeType.h"
#include "../include/WeightType.h"

using namespace std;

class MinHeap{
    public:
        /* Structure to store node of the heap*/
        struct HeapNode{
            NodeType node;
            WeightType dist;
        };

    private:
        int size;                   // No of nodes in heap currently
        int capacity;               // Max number of nodes that can be in heap
        int* position;              // Position of vertex in the heap
        struct HeapNode **heap;     // Heap array

    public:
        /*  Constructor */
        MinHeap (int cap){
            size = 0;
            capacity = cap;
            heap = new HeapNode*[capacity];
            position = new int[capacity];
            for(int i=0; i<capacity; i++){
                heap[i] = NULL;
                position[i] = -1;
            }
        }
        
        /* Member functions */

        struct HeapNode* createHeapNode(NodeType node, WeightType dist);
        void swapHeapNode(struct HeapNode** a, struct HeapNode** b);
    
        /* Updates the value of node with new weight value*/
        void decreaseKey(NodeType, WeightType );
        void insert(NodeType node, WeightType dist);
        void minHeapify(NodeType idx);
        struct HeapNode* deleteRoot();
        void printHeap();
        bool isEmpty();
        bool inHeap(int v);
};

#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of MinHeap.h
 **************************************************************************/