#include <iostream>
#include "string.h"
using namespace std;
typedef int elementType;
typedef struct cellType* Position;
typedef struct cellType {
  elementType value;
  Position next;
} CellNode;
class List {
public:
  void insert(elementType x, Position p);
  void delItem(Position p);
  void makeNull();
  void printList();
  elementType retrieve (Position p);
  Position end();
  Position first();
  Position next(Position p);
private:
  Position listHead;
};
void List::makeNull() {
  listHead = new CellNode;
  listHead->next = NULL;
}
void List::insert(elementType x, Position p) {
  Position temp;
  temp = p->next;
  p->next = new cellType;
  p->next->next  = temp;
  p->next->value = x;
}
elementType List::retrieve(Position p) {
  return(p->next->value);  
}
void List::printList() {
  Position p;
  p = listHead->next;
  while (p != NULL) {
    cout << p->value;
    p = p->next;
  }
  cout << endl;
 }
Position List::end() {
  Position p;
  p = listHead;
  while (p->next != NULL)
    p = p->next;
  return(p);
}
void List::delItem(Position p) {
   p->next = p->next->next;
}
Position List::first() {
  return(listHead);
}
Position List::next(Position p) {
  return (p->next);
}



 /******************************************************************************
   BigInt : Takes as input two BigIntegers and returns their sum
   inputs : string1, string2
   outputs : BigIntAdd -- the sum of the two integers in another string.
******************************************************************************/

List  BigIntAdd( char *string1, char *string2) {

  
/**************************************************************************
	
    Write your Code Here to complete

**************************************************************************/
}

int main(){
  char string1[101], string2[101];
  int tcs;
  cin>>tcs;
  List result;

  for(int i=0;i<tcs;i++){
    cin >> string1;
    cin >> string2;
    cout<<string1<<" + "<<string2<<" = ";
    result = (List) BigIntAdd (string1, string2);    
    result.printList();    
  }

  return 0;
}