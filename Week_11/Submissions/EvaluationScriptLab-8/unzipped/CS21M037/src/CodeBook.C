/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	CodeBook.C
 *
 *  Purpose:	Implementation of Code book using huffman tree
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
#include "../include/HuffmanTree.h"
#include "../include/CodeBook.h"

using namespace std;

/******************************************************************************
   Sort : Stable Sorts the array of nodes based on their probability
   inputs : arr - array of nodes
            n - size of array
   outputs : No Outputs
******************************************************************************/
void Sort(HuffManTree *arr, int n) {
  int   i, j;                           /* Iterator variables */
  // Stable Bubble Sort
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if ((arr[j]).getProbability() > (arr[j + 1]).getProbability()) {
        // Swap nodes
        HuffManTree temp = (arr[j]);
        arr[j] = (arr[j + 1]);
        arr[j + 1] = temp;
      }
    }
  }
}

/**************************************************************************
 * $Log$
 *
 * End:
 *                        End of CodeBook.C
 **************************************************************************/