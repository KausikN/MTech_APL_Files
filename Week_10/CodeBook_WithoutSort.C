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
};

/******************************************************************************
   PreorderTraversal : Performs Preorder traversal of the tree and displays the codes of letters
   inputs : tree - current Node
            curCode - current code
            codeSize - current code Length
   outputs : No Outputs
******************************************************************************/
void PreorderTraversal(HuffManTree *tree, char* curCode, int codeSize) {
  if (tree == NULL)
    return;
  char* lstr = new char[codeSize];
  char* rstr = new char[codeSize];
  for (int i=0;i<codeSize;i++){
    lstr[i] = curCode[i];
    rstr[i] = curCode[i];
  }
  lstr[codeSize] = '1';
  rstr[codeSize] = '0';
  PreorderTraversal(tree->getLeftTree(), lstr, codeSize+1);
  if (tree->getSymbol() != 'I'){
    cout<<tree->getSymbol()<<" ";
    for (int i=0; i<codeSize; i++){
      cout<<curCode[i];
    }
    if (codeSize > 0){
      cout<<endl;
    }
  }
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
   makeBinaryTree : Sets the minimum of the two inputs as left subtree and other
                    input as right subtree to the current node
   inputs : ltree - pointer to left subtree
            rtree - pointer to right subtree
   outputs : No Outputs
******************************************************************************/
void HuffManTree::makeBinaryTree(HuffManTree *ltree, HuffManTree *rtree) {
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
  char* curCode = "";
  PreorderTraversal(tree, curCode, 0);
}

void Swap(HuffManTree *node1, HuffManTree *node2) {
  HuffManTree *temp = node1;
  node1 = node2;
  node2 = temp;
}

void Sort(HuffManTree *arr, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if ((arr[j]).getProbability() > (arr[j + 1]).getProbability()) {
        Swap(&(arr[j]), &(arr[j + 1]));
      }
    }
  }
}

int main() {
  HuffManTree huff[50];
  
  int num;
  int i;
  float prob[30];
  
  cin >> num;
 
  for (i = 0; i < num; i++) {
    cin >> prob[i];
    huff[i] = HuffManTree(prob[i], 'I');
    huff[i].setProbability(prob[i]);
    huff[i].setSymbol((char)('a'+i));
    huff[i].setLeftTree(NULL);
    huff[i].setRightTree(NULL);
  }
  
  /* Complete your code here*/
  int charsAddedCheck[50] = {0};              /* Array to check if a node has been added to the tree */
  int nodeCount = num;                        /* Counts number of nodes */

  // Keep looping until all letters are added to the tree
  while(1) {
    int min1 = -1;                            /* Index of minimum probability of nodes not yet added to tree */
    int min2 = -1;                            /* Index of 2nd minimum probability of nodes not yet added to tree */
    for (int j = 0; j < nodeCount; j++) {
      // Consider only nodes which are not yet added to the tree
      if (charsAddedCheck[j] == 0){
        // Initial Case
        if (min1 == -1){
          min1 = j;
        }
        else if (min2 == -1){
          min2 = j;
        }
        // If current node prob is lesser than min1, replace min1 by j and min2 by min1
        else if (huff[j].getProbability() < huff[min1].getProbability()) {
          min2 = min1;
          min1 = j;
        }
        // If current node prob is greater than min1, but lesser than min2 replace min2 by j
        else if (huff[j].getProbability() < huff[min2].getProbability()) {
          min2 = j;
        }
      }
    }
    // Break if no nodes are left to be added to the tree
    if (min1 == -1 || min2 == -1) {
      break;
    }

    // Set check for added to tree as 1 for the two nodes
    charsAddedCheck[min1] = 1;
    charsAddedCheck[min2] = 1;

    // Create a new node with prob = sum of prob of min1 and min2
    huff[nodeCount] = HuffManTree(huff[min1].getProbability() + huff[min2].getProbability(), 'I');
    huff[nodeCount].createBinaryTree(huff[min1].getProbability() + huff[min2].getProbability(), 'I');
    // If probs are equal
    if (huff[min1].getProbability() == huff[min2].getProbability()) {
      
    }
    else {
      huff[nodeCount].makeBinaryTree(&huff[min1], &huff[min2]);
    }

    cout<<"IT "<<nodeCount<<": "<<endl;
    cout<<"min1 "<<min1<<" "<<huff[min1].getSymbol()<<" "<<huff[min1].getProbability()<<endl;
    cout<<"min2 "<<min2<<" "<<huff[min2].getSymbol()<<" "<<huff[min2].getProbability()<<endl<<endl;

    nodeCount++;
  }
  huff[0].printCodes(&huff[nodeCount-1]);

  return(0);
}