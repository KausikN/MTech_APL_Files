/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	MinHeap.C
 *
 *  Purpose:	Implementation of MinHeap
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

#include "../include/MinHeap.h"
#include "../include/NodeType.h"
#include "../include/WeightType.h"

/******************************************************************************
   createHeapNode : Creates a new HeapNode
   inputs : node - Node to be added
            dist - Distance of the node from source
   outputs : Pointer to the new HeapNode
******************************************************************************/
struct MinHeap::HeapNode* MinHeap::createHeapNode(NodeType node, WeightType dist){
    struct HeapNode* newNode = new HeapNode;        /* Pointer to new heap node */
    newNode->node = node;
    newNode->dist = dist;
    return newNode;
}

/******************************************************************************
   swapHeapNode : Swaps two HeapNodes
   inputs : a - Heap Node 1
            b - Heap Node 2
   outputs : No Outputs
******************************************************************************/
void MinHeap::swapHeapNode(struct HeapNode** a, struct HeapNode** b){
    struct HeapNode* temp = *a;       
    *a = *b;
    *b = temp;
}

/******************************************************************************
   decreaseKey : Updates the value of node with new dist value
   inputs : node - node
            dist - new dist
   outputs : No Outputs
******************************************************************************/
void MinHeap::decreaseKey(NodeType node, WeightType dist){
    // If new distance is more than current distance, dont Update
    if (dist > (heap[position[node]])->dist){
        return;
    }

    int i = position[node];                         /* Position of node */
    heap[i]->dist = dist;                           /* Update the weight in heap array */

    // Loop if the node is not root (i == 0) and dist of i is less than parent ((i-1)/2 th position)
    int iParent = (i-1)/2;                          /* Position of parent of i */
    while(i > 0 && heap[i]->dist < heap[iParent]->dist){
        swapHeapNode(&heap[i], &heap[iParent]);
        position[heap[i]->node] = i;
        position[heap[iParent]->node] = iParent;
        i = iParent;
        iParent = (i-1)/2;
    }
}

/******************************************************************************
   insert : Inserts a new node in the heap
   inputs : node - node
            dist - dist of node
   outputs : No Outputs
******************************************************************************/
void MinHeap::insert(NodeType node, WeightType dist){
    // If heap is full, dont insert
    if(size == capacity){
        return;
    }

    // Create new heap node
    struct HeapNode* newNode = createHeapNode(node, dist);  /* Pointer of new node */
    heap[size] = newNode;
    position[node] = size;
    size++;

    // Update the heap
    decreaseKey(node, dist);
}

/******************************************************************************
   minHeapify : Heapifies the heap
   inputs : idx - node id
   outputs : No Outputs
******************************************************************************/
void MinHeap::minHeapify(NodeType idx){
    int i = idx;                                /* Current smallest index */
    int l = (2*i + 1);                          /* Left child index */
    int r = (2*i + 2);                          /* Right child index */

    // If left child position < i, set i as left child position
    if(l < size && heap[l]->dist < heap[i]->dist){
        i = l;
    }

    // If right child position < i, set i as right child position
    if(r < size && heap[r]->dist < heap[i]->dist){
        i = r;
    }

    // If i is not root, swap i and idx and recursively call minHeapify on i
    if(i != idx){
        swapHeapNode(&heap[i], &heap[idx]);
        position[heap[idx]->node] = idx;
        position[heap[i]->node] = i;
        minHeapify(i);
    }
}

/******************************************************************************
   deleteRoot : Deletes the root of the heap
   inputs :  No Inputs
   outputs : Pointer to the root of the heap
******************************************************************************/
struct MinHeap::HeapNode* MinHeap::deleteRoot(){
    // If heap is empty, return NULL
    if (isEmpty())
        return NULL;

    struct HeapNode* root = heap[0];            /* Pointer to root of heap */

    // Change the root to the last element in heap array
    heap[0] = heap[size-1];
    position[root->node] = size-1;
    position[heap[0]->node] = 0;
    size--;

    // Heapify the heap
    minHeapify(0);

    // Return the pointer to the deleted root
    return root;
}

/******************************************************************************
   printHeap : Prints the heap
   inputs :  No Inputs
   outputs : No Outputs
******************************************************************************/
void MinHeap::printHeap(){
    for(int i = 0; i < size; i++){
        cout << heap[position[i]]->node << " " << heap[position[i]]->dist << endl;
    }
}

/******************************************************************************
   isEmpty : Checks if the heap is empty
   inputs :  No Inputs
   outputs : true if heap is empty, false otherwise
******************************************************************************/
bool MinHeap::isEmpty(){
    return (size == 0);
}

/******************************************************************************
   inHeap : Checks if the node is in the heap
   inputs :  v - vertex to be checked
   outputs : true if node is in heap, false otherwise
******************************************************************************/
bool MinHeap::inHeap(int v){
    if (position[v] >= 0 && position[v] < size)
        return true;
    return false;
}

/**************************************************************************
 * $Log$
 *
 * End:
 *                        End of MinHeap.C
 **************************************************************************/