#include <iostream>
#include <algorithm>
using namespace std;
typedef int elementType;
typedef int Position;

class List {
public:
  void insert(elementType x, Position p);
  void delItem(Position p);
  void makeNull();
  void printList();
  Position end();
  Position first();
  Position next(Position p);
  elementType retrieve(Position p);
  
private:
  Position lastNode;
  elementType*  list;
};
void List::makeNull() {
  list = new elementType[100000]; 
  lastNode = 0;
}
void List::insert(elementType x, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p] = x;
  lastNode++;
}
void List::printList() {
  Position p;
  p = 1;
  
  while (p <= lastNode) {
    cout << list[p] << " ";
    p++;
  }
 }
Position List::end() {
  Position p;
  p = lastNode + 1;
  
  return(p);
}
void List::delItem(Position p) {
  int i;
  for (i = p; i < lastNode; i++)
    list[i] = list[i+1];
  lastNode = lastNode - 1;
}
Position List::first() {
  return(1);
}
Position List::next(Position p) {
  return (p+1);
}

elementType List::retrieve (Position p) {
  return (list[p]);
}

int Same (elementType x, elementType y) {
  if (x == y) 
    return(1);
  else
    return(0);
}
int IsGreater(elementType x, elementType y){
  if (x >= y) 
    return(1);
  else
    return(0);
}


List sortlist(List &l){
  
  
  /* Write your code here*/
  
  
}


int main() {
  List         a, b;
  int          i;
  elementType *array1;
  int         n1;
  
  
  cin >> n1;
  array1 = new elementType[n1];
  

  
  for (i = 0; i < n1; i++)
    cin >> array1[i];
  
  a.makeNull();
  
  for (i = 0; i < n1; i++)
    a.insert(array1[i],a.end());
  
  cout<<"The original list before sorting: ";
  a.printList();
  cout<<endl;
  
  b = (List) sortlist(a);

  cout<<"The sorted list: ";
  a.printList();

  return 0;
}