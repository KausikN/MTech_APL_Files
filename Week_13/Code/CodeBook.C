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
  
  /* Complete your code here*/
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