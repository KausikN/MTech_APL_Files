/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	HuffmanTree.C
 *
 *  Purpose:	Implementation of Huffman Tree
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

using namespace std;

/******************************************************************************
   PreorderTraversal : Performs Preorder traversal of the tree and displays the codes of letters
   inputs : tree - current Node
            curCode - current code
            codeSize - current code Length
   outputs : No Outputs
******************************************************************************/
void HuffManTree::PreorderTraversal(HuffManTree *tree, char* curCode, int codeSize) {
  // If current node is NULL, stop
  if (tree == NULL)
    return;

  char*   lstr = new char[codeSize];    /* Code for the left subtree of current node */
  char*   rstr = new char[codeSize];    /* Code for the right subtree of current node */
  // Initialize lstr and rstr as current code
  for (int i = 0; i < codeSize; i++){
    lstr[i] = curCode[i];
    rstr[i] = curCode[i];
  }
  lstr[codeSize] = '1';               /* Add a '1' to the end of lstr for left subtree */
  rstr[codeSize] = '0';               /* Add a '0' to the end of rstr for right subtree */

  // Recursion to left subtree
  PreorderTraversal(tree->getLeftTree(), lstr, codeSize+1);

  // Print code of current node if it is a charecter symbol
  if (tree->getSymbol() != 'I'){
    cout<<tree->getSymbol()<<" ";
    for (int i = 0; i < codeSize; i++){
      cout<<curCode[i];
    }
    if (codeSize > 0){
      cout<<endl;
    }
  }

  // Recursion to right subtree
  PreorderTraversal(tree->getRightTree(), rstr, codeSize+1);
}

/******************************************************************************
   createBinaryTree : Creates binary tree with the given probability and symbol
   inputs : prob - probability of node
            letter - symbol of node
   outputs : No Outputs
******************************************************************************/
void HuffManTree::createBinaryTree(float prob, char letter) {
  symbol = letter;
  probability = prob;
  lChild = NULL;
  rChild = NULL;
}

/******************************************************************************
   makeBinaryTree : Sets the minimum probability node of the two inputs as left subtree and other
                    input as right subtree to the current node
   inputs : ltree - pointer to left subtree
            rtree - pointer to right subtree
   outputs : No Outputs
******************************************************************************/
void HuffManTree::makeBinaryTree(HuffManTree *ltree, HuffManTree *rtree) {
  // lChild is assigned the smaller probability node and rChild the other node
  if (ltree->getProbability() <= rtree->getProbability()) {
    lChild = ltree;
    rChild = rtree;
  }
  else {
    lChild = rtree;
    rChild = ltree;
  }
}

/******************************************************************************
   getSymbol : Returns the symbol of the current node in the HuffmanTree
   inputs : No Inputs
   outputs : symbol - symbol of the current node
******************************************************************************/
char HuffManTree::getSymbol() {
  return symbol;
}

/******************************************************************************
   getProbability : Returns the probability of the current node in the HuffmanTree
   inputs : No Inputs
   outputs : probability - probability of the current node
******************************************************************************/
float HuffManTree::getProbability() {
  return probability;
}

/******************************************************************************
   setSymbol : Sets the symbol of the current node in the HuffmanTree
   inputs : sym - symbol to be set
   outputs : No Outputs
******************************************************************************/
void HuffManTree::setSymbol(char sym) {
  symbol = sym;
}

/******************************************************************************
   setProbability : Sets the probability of the current node in the HuffmanTree
   inputs : prob - probability to be set
   outputs : No Outputs
******************************************************************************/
void HuffManTree::setProbability(float prob) {
  probability = prob;
}

/******************************************************************************
   getLeftTree : Returns the left subtree of the current node in the HuffmanTree
   inputs : No Inputs
   outputs : lChild - left subtree of the current node
******************************************************************************/
HuffManTree* HuffManTree::getLeftTree() {
  return lChild;
}

/******************************************************************************
   getRightTree : Returns the right subtree of the current node in the HuffmanTree
   inputs : No Inputs
   outputs : rChild - right subtree of the current node
******************************************************************************/
HuffManTree* HuffManTree::getRightTree() {
  return rChild;
}

/******************************************************************************
   setLeftTree : Sets the left subtree of the current node in the HuffmanTree
   inputs : ltree - pointer to the left subtree to be set
   outputs : No Outputs
******************************************************************************/
void HuffManTree::setLeftTree(HuffManTree *ltree) {
  lChild = ltree;
}

/******************************************************************************
   setRightTree : Sets the right subtree of the current node in the HuffmanTree
   inputs : rtree - pointer to the right subtree to be set
   outputs : No Outputs
******************************************************************************/
void HuffManTree::setRightTree(HuffManTree *rtree) {
  rChild = rtree;
}

/******************************************************************************
   printCodes : Prints the codes of letters using preorder traversal
   inputs : tree - pointer to the head of the Huffman Tree
   outputs : No Outputs
******************************************************************************/
void HuffManTree::printCodes(HuffManTree *tree) {
  char*   curCode = (char *)"";           /* Initialise the current code as empty string */

  // Print the codes using preorder traversal of the tree
  this->PreorderTraversal(tree, curCode, 0);
}

/**************************************************************************
 * $Log$
 *
 * End:
 *                        End of HuffmanTree.C
 **************************************************************************/