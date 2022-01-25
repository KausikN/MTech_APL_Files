
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