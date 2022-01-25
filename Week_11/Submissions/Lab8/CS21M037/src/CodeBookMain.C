/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	CodeBookMain.C
 *
 *  Purpose:	Main file for generating a code book using huffman trees
 *            and printing the codes of charecters.
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
#include "../include/CodeBook.h"
#include "../include/HuffmanTree.h"

/******************************************************************************
   main : Main function to run the program
   inputs : No Inputs
   outputs : 0 if no errors
******************************************************************************/
int main() {
  HuffManTree huff[50];
  
  int num;
  int i;
  float prob[30];
  
  cin >> num;
 
  for (i = 0; i < num; i++) {
    cin >> prob[i];

    huff[i].setProbability(prob[i]);
    huff[i].setSymbol((char)('a'+i));
    huff[i].setLeftTree(NULL);
    huff[i].setRightTree(NULL);
  }

  int   charsAddedCheck[50] = {0};      /* Array to check if a node has been added to the tree */
  int   nodeCount = num;                /* Counts number of nodes */

  // Keep looping until all nodes are added to the tree
  while(1) {
    // Stable Sort the nodes by probability
    Sort(huff, nodeCount);

    int   min1 = -1;                    /* Index of minimum probability of nodes not yet added to tree */
    int   min2 = -1;                    /* Index of 2nd minimum probability of nodes not yet added to tree */
    for (int j=0; j<nodeCount; j++){
      // Consider only nodes which are not yet added to the tree
      if (charsAddedCheck[j] == 0) {
        if (min1 == -1) {
          min1 = j;
        }
        else if (min2 == -1) {
          min2 = j;
          break;
        }
      }
    }
    // Break if no nodes are left to be added to the tree
    // If we dont get a min1 or min2, then all nodes are added to the tree
    if (min1 == -1 || min2 == -1) {
      break;
    }

    // Set check for added to tree as 1 for the two minimum nodes
    charsAddedCheck[min1] = 1;
    charsAddedCheck[min2] = 1;

    // Create a new node with prob = sum of prob of min1 and min2
    huff[nodeCount] = HuffManTree(huff[min1].getProbability() + huff[min2].getProbability(), 'I');
    huff[nodeCount].createBinaryTree(huff[min1].getProbability() + huff[min2].getProbability(), 'I');
    // Set the two minimum probability nodes as lChild and rChild to the new node
    // If min1 and min2 probabilities are equal
    if (huff[min1].getProbability() == huff[min2].getProbability()) {
      // Set ltree as the symbol which arrived first and rtree as the symbol which arrived later
      // Since sort is stable, the order of symbols with same prob is preserved
      int   lIndex = min1;              /* index for lChild */
      int   rIndex = min2;              /* index for rChild */
      // min1 arrived later, i.e. min1 > min2, assign min2 as lChild and min1 as rChild
      if (min1 > min2){
        lIndex = min2;
        rIndex = min1;
      }
      huff[nodeCount].makeBinaryTree(&huff[lIndex], &huff[rIndex]);
    }
    else {
      huff[nodeCount].makeBinaryTree(&huff[min1], &huff[min2]);
    }

    nodeCount++;
  }

  // Print the codes of the symbols
  huff[0].printCodes(&huff[nodeCount-1]);

  return(0);
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of CodeBookMain.C
 **************************************************************************/