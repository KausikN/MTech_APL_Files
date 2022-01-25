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
 
  return(0);
}