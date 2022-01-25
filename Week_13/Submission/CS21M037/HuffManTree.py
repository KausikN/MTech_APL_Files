#************************************************************************
#  $Id$
#  Release $Name$
#
#  File:	HuffManTree.py
#
#  Purpose:	Implementation of Huffman Encoding
#
#  Author:	CS21M037, N Kausik
#
#  Created:    08-11-2021
#
#  Last modified:  
#
#  Bugs:	
#
#  Change Log:	
#  
#
#*************************************************************************

# Huffman Tree Class
class HuffManTree:
  def __init__(self, prob=0, letter='I'):
    self.symbol = letter
    self.probability = prob
    self.lChild = None
    self.rChild = None

  #******************************************************************************
  # createBinaryTree : Creates binary tree with the given probability and symbol
  # inputs : prob - probability of node
  #          letter - symbol of node
  # outputs : No Outputs
  #******************************************************************************
  def createBinaryTree(self, prob, letter):
    self.symbol = letter
    self.probability = prob
    self.lChild = None
    self.rChild = None

  #******************************************************************************
  # makeBinaryTree : Sets the minimum probability node of the two inputs as left subtree and other
  #                  input as right subtree to the current node
  # inputs : ltree - left subtree
  #          rtree - right subtree
  # outputs : No Outputs
  #******************************************************************************
  def makeBinaryTree(self, ltree, rtree):
    # lChild is assigned the smaller probability node and rChild the other node
    if (ltree.getProbability() <= rtree.getProbability()):
      self.lChild = ltree
      self.rChild = rtree
    else:
      self.lChild = rtree
      self.rChild = ltree

  #******************************************************************************
  #   getSymbol : Returns the symbol of the current node in the HuffmanTree
  #   inputs : No Inputs
  #   outputs : symbol - symbol of the current node
  #******************************************************************************
  def getSymbol(self):
    return self.symbol

  #******************************************************************************
  # getProbability : Returns the probability of the current node in the HuffmanTree
  # inputs : No Inputs
  # outputs : probability - probability of the current node
  #******************************************************************************
  def getProbability(self):
    return self.probability

  #******************************************************************************
  # setSymbol : Sets the symbol of the current node in the HuffmanTree
  # inputs : sym - symbol to be set
  # outputs : No Outputs
  #******************************************************************************
  def setSymbol(self, sym):
    self.symbol = sym

  #******************************************************************************
  # setProbability : Sets the probability of the current node in the HuffmanTree
  # inputs : prob - probability to be set
  # outputs : No Outputs
  #******************************************************************************
  def setProbability(self, prob):
    self.probability = prob

  #******************************************************************************
  # getLeftTree : Returns the left subtree of the current node in the HuffmanTree
  # inputs : No Inputs
  # outputs : lChild - left subtree of the current node
  #******************************************************************************
  def getLeftTree(self):
    return self.lChild

  #******************************************************************************
  # getRightTree : Returns the right subtree of the current node in the HuffmanTree
  # inputs : No Inputs
  # outputs : rChild - right subtree of the current node
  #******************************************************************************
  def getRightTree(self):
    return self.rChild

  #******************************************************************************
  # setLeftTree : Sets the left subtree of the current node in the HuffmanTree
  # inputs : ltree - left subtree to be set
  # outputs : No Outputs
  #******************************************************************************
  def setLeftTree(self, ltree):
    self.lChild = ltree

  #******************************************************************************
  # setRightTree : Sets the right subtree of the current node in the HuffmanTree
  # inputs : rtree - right subtree to be set
  # outputs : No Outputs
  #******************************************************************************
  def setRightTree(self, rtree):
    self.rChild = rtree

  #******************************************************************************
  # printCodes : Prints the codes of letters using preorder traversal
  # inputs : tree - head of the Huffman Tree
  # outputs : No Outputs
  #******************************************************************************
  def printCodes(self, tree):
    curCode = ""          # Initialise the current code as empty string

    # Print the codes using preorder traversal of the tree
    self.PreorderTraversal(tree, curCode)

  #******************************************************************************
  # PreorderTraversal : Performs Preorder traversal of the tree and displays the codes of letters
  # inputs : tree - current Node
  #          curCode - current code
  # outputs : No Outputs
  #******************************************************************************
  def PreorderTraversal(self, tree, curCode):
    # If current node is None, stop
    if (tree is None):
      return None

    # Initialize lstr and rstr as current code
    lstr = str(curCode)    # Code for the left subtree of current node
    rstr = str(curCode)    # Code for the right subtree of current node
    
    lstr = lstr + "1"      # Add a '1' to the end of lstr for left subtree
    rstr = rstr + "0"      # Add a '0' to the end of rstr for right subtree

    # Recursion to left subtree
    self.PreorderTraversal(tree.getLeftTree(), lstr)

    # Print code of current node if it is a charecter symbol
    if (not (tree.getSymbol() == 'I')):
      print(tree.getSymbol() + " " + curCode)

    # Recursion to right subtree
    self.PreorderTraversal(tree.getRightTree(), rstr)

#**************************************************************************
# $Log$
# 
# End:
#                        End of HuffManTree.py
#*************************************************************************