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

List sortlist_BubbleSort(List &l){

    Position    i = l.first();                          /* Iterator for outer loop */
    Position    j = l.first();                          /* Iterator for inner loop */

    // Bubble Sort
    // Loop through all elements in the list
    while(i < l.end()){
        j = l.first();                                  /* Reset the inner iterator to start of list */
        // Loop from start of list to (size of list - i - 1)
        // Since after every outer loop iteration, the last i elements are in sorted order
        while(j < l.end()-i){
            // Swap if the jth element is greater than (j+1)th element
            if (IsGreater(l.retrieve(j), l.retrieve(l.next(j)))){
                // Swapping elements in the list inplace using deletion and insertions
                elementType elementJ = l.retrieve(j);   /* Save element at position j */
                l.delItem(j);                           /* Delete element at position j */
                l.insert(l.retrieve(j), j);             /* Insert (j+1)th element at position j */
                l.delItem(l.next(j));                   /* Delete element at position j+1 */
                l.insert(elementJ, l.next(j));          /* Insert original jth element at position j+1 */
            }
            j = l.next(j);                              /* Goto next position after j */
        }
        i = l.next(i);                                  /* Goto next position after i */
    }

    return(l);                                          /* Return sorted list */
}

List sortlist(List &l){

    int    i = l.first();                               /* Iterator for outer loop */
    int    j = l.first();                               /* Iterator for inner loop */
    int    largestElement = l.first();                  /* Stores the position of largest value seen */

    // Selection Sort
    // Loop through all elements in the list
    while(i < l.end()){
        j = l.first();                                  /* Reset the inner iterator to next element after start of list */
        largestElement = l.first();                     /* Reset the largestElement position */
        // Loop from start of list to (end - i)
        // Since after every outer loop iteration, the last i elements are in sorted order
        while(j < l.end()-i+1){
            // Change largestElement if the jth element is greater than current largestElement
            if (IsGreater(l.retrieve(j), l.retrieve(largestElement))){
                largestElement = j;
            }
            j = l.next(j);                              /* Goto next position after j */
        }

        // Move largest element to end - i
        if ((largestElement != (l.end()-i)) && !Same(l.retrieve(largestElement), l.retrieve(l.end()-i))) {
            // Swapping elements in the list inplace using deletion and insertions
            /* Insert largest element after position (end - i) */
            l.insert(l.retrieve(largestElement), l.end()-i+1);
            /* Delete element at position largestElement */
            l.delItem(largestElement);
        }

        i = l.next(i);                                  /* Goto next position after i */
    }

    return(l);                                          /* Return sorted list */
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