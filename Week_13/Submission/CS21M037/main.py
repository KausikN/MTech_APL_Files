#************************************************************************
#  $Id$
#  Release $Name$
#
#  File:	main.py
#
#  Purpose:	Main for Generating Code Book using Huffman Encoding
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

# Imports
from HuffManTree import *

#******************************************************************************
# Sort : Stable Sorts the array of nodes based on their probability
# inputs : n - size of array
# outputs : No Outputs
#******************************************************************************
def Sort(n):
  global huff
  global charsAddedCheck

  # Stable Bubble Sort
  for i in range(n-1):
    for j in range(n-i-1):
      if ((huff[j]).getProbability() > (huff[j + 1]).getProbability()):
        # Swap nodes
        huff[j], huff[j+1] = huff[j+1], huff[j]
        charsAddedCheck[j], charsAddedCheck[j+1] = charsAddedCheck[j+1], charsAddedCheck[j]

# Main Program

huff = [None] * 100           # Array of Huffman Tree nodes
prob = [0.0] * 30             # Array of probabilities

num = int(input())            # Number of symbols

# Get probabilities of symbols and create Huffman Tree Nodes for each symbol
for i in range(num):
  prob[i] = float(input())

  huff[i] = HuffManTree()
  huff[i].setProbability(prob[i])
  huff[i].setSymbol(str(chr(ord('a') + i)))
  huff[i].setLeftTree(None)
  huff[i].setRightTree(None)

charsAddedCheck = [False] * 100 # Array to check if a node has been added to the tree
nodeCount = num                 # Counts number of nodes

# Keep looping until all nodes are added to the tree
while(True):
  # Stable Sort the nodes by probability
  Sort(nodeCount)

  min1 = -1                     # Index of minimum probability of nodes not yet added to tree
  min2 = -1                     # Index of 2nd minimum probability of nodes not yet added to tree
  for j in range(nodeCount):
    # Consider only nodes which are not yet added to the tree
    if (charsAddedCheck[j] == False):
      if (min1 == -1):
        min1 = j
      elif (min2 == -1):
        min2 = j
        break

  # Break if no nodes are left to be added to the tree
  # If we dont get a min1 or min2, then all nodes are added to the tree
  if ((min1 == -1) or (min2 == -1)):
    break

  # Set check for added to tree as True for the two minimum nodes
  charsAddedCheck[min1] = True
  charsAddedCheck[min2] = True

  # Create a new node with prob = sum of prob of min1 and min2
  huff[nodeCount] = HuffManTree()
  huff[nodeCount].createBinaryTree(huff[min1].getProbability() + huff[min2].getProbability(), 'I')
  # Set the two minimum probability nodes as lChild and rChild to the new node
  # If min1 and min2 probabilities are equal
  if (huff[min1].getProbability() == huff[min2].getProbability()):
    # Set ltree as the symbol which arrived first and rtree as the symbol which arrived later
    # Since sort is stable, the order of symbols with same prob is preserved
    lIndex = min1               # index for lChild
    rIndex = min2               # index for rChild
    # min1 arrived later, i.e. min1 > min2, assign min2 as lChild and min1 as rChild
    if (min1 > min2):
      lIndex = min2
      rIndex = min1
    
    huff[nodeCount].makeBinaryTree(huff[lIndex], huff[rIndex])
  else:
    huff[nodeCount].makeBinaryTree(huff[min1], huff[min2])

  nodeCount += 1

# Print the codes of the symbols
huff[0].printCodes(huff[nodeCount-1])

#**************************************************************************
# $Log$
# 
# End:
#                        End of main.py
#*************************************************************************