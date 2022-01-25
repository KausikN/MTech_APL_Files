/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	HuffmanTree.h
 *
 *  Purpose:	Header file for implementation of Huffman Tree
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

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include <iostream>

using namespace std;

class HuffManTree {
  char symbol;
  float probability;
  HuffManTree *lChild, *rChild;
  public:
  HuffManTree(){
  }
  HuffManTree(float prob, char letter) {
    symbol = 'I';
    probability = 0;
    lChild = NULL;
    rChild = NULL;
  }
  
  HuffManTree (float prob, char letter, HuffManTree *lChild, HuffManTree *rChild) {
    probability  = prob;
    symbol = letter;
    lChild = NULL;
    rChild = NULL;
  }
  
  void createBinaryTree(float prob, char letter);
  void makeBinaryTree(HuffManTree *ltree, HuffManTree *rtree);
  char getSymbol();
  float getProbability();
  void setSymbol(char sym);
  void setProbability(float prob);
  HuffManTree *getLeftTree();
  HuffManTree *getRightTree();
  void setLeftTree(HuffManTree *ltree);
  void setRightTree(HuffManTree *rtree);
  void printCodes (HuffManTree *tree);

  void PreorderTraversal(HuffManTree *tree, char* curCode, int codeSize);
};
#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of HuffmanTree.h
 **************************************************************************/