/*-------------------------------------------------------------------------
 *  ListPolynomial.C - Polynomial Arithmetic using Lists
 *  Version:	$Name$
 *  Module:	
 *
 *  Purpose:	
 *  See:	
 *
 *  Author:	hema arunachalam (hema@hemas-MacBook-Pro.local)
 *
 *  Created:        Wed 02-Sep-2020 10:39:58
 *  Last modified:  Wed 2-Sep-2020 11:06:25 by hema
 *  $Id$
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 -------------------------------------------------------------------------*/
#include <iostream>
#include "ElementType.h"
#include "ListADTArray.h"
List PolynomialMult (List A, List B) {
 Position ptr;
  int coeff1, coeff2;
  int degree1, degree2;
  ElementType node1, node2, node, nodeTemp;
  Position ptr1, ptr2,prevPtr;
  List C;
  C.makeNull();
  ptr1 = A.first();
  while (ptr1 != A.end()) {
    node1 = (ElementType) A.retrieve (ptr1);
    ptr2 = B.first();
    while (ptr2 != B.end()) {
      node2 = (ElementType) B.retrieve (ptr2);
      node.coefft = node1.coefft*node2.coefft;
      node.degree = node1.degree + node2.degree;
      ptr = C.locate(node);
      if (!ptr)
	C.insert(node, C.end());
      else {
	nodeTemp = (ElementType) C.retrieve(ptr);
	//	prevPtr = C.prev(ptr);
	node.coefft = node.coefft + nodeTemp.coefft;
	C.replace(node, ptr);
      }
      C.printList();
      ptr2 = B.next(ptr2);
    }
    ptr1 = A.next(ptr1);
  }
  return(C);
}
List PolynomialAdd (List A, List B) {
  Position ptr;
  int coeff1, coeff2;
  int degree1, degree2;
  ElementType node1, node2, node;
  Position ptr1, ptr2;
  List C;
  C.makeNull();
  ptr1 = A.first();
  ptr2 = B.first();
  while ((ptr1 != A.end()) && (ptr2 != B.end())) {
    node1 = (ElementType) A.retrieve(ptr1);
    node2 = (ElementType) B.retrieve(ptr2);
    if (node1.degree == node2.degree) {
      node.coefft = node1.coefft + node2.coefft;
      node.degree = node1.degree;
      C.insert(node, C.end());
      ptr1 = A.next(ptr1);
      ptr2 = B.next(ptr2);
    } else if (node1.degree > node2.degree) {
      node.coefft = node1.coefft;
      node.degree = node1.degree;
      C.insert(node, C.end());
      ptr1 = A.next(ptr1);
    } else {
      node.coefft = node2.coefft;
      node.degree = node2.degree;
      C.insert(node, C.end());
      ptr2 = B.next(ptr2);
    }
  }
  if (ptr1 != A.end())
    while (ptr1 != A.end()) {
      node1 = (ElementType) A.retrieve(ptr1);
      node.coefft = node1.coefft;
      node.degree = node1.degree;
      C.insert(node, C.end());
      ptr1 = A.next(ptr1);
    }
  else
    while (ptr2 != B.end()) {
      node2 = (ElementType) B.retrieve(ptr2);
      node.coefft = node2.coefft;
      node.degree = node2.degree;
      C.insert(node, C.end());
      ptr2 = B.next(ptr2);
    }
  return(C);
}
int main() {
  List a, b, c,d;
  ElementType nodeA, nodeB;
    int m, n;
    int i;
    //cout << "input number of terms in Polynomials A and B:"<< endl;
    cin >> m >> n;
    //cout << "input the polynomial A in the form coefft1 degree1 coefft2 degree2 ... coefftm, degreem "<< endl;
    a.makeNull();
    for (i = 0; i < m; i++) {
      cin >> nodeA.coefft >>  nodeA.degree;
      a.insert(nodeA, a.end());
    }
    //cout << "Printing Polynomial A:" << endl;
    //a.printList();
    //cout << "input the polynomial B in the form coefft1 degree1 coefft2 degree2 ... coefftm, degreem "<< endl;
    b.makeNull();
    for (i = 0; i < n; i++) {
      cin >> nodeB.coefft >> nodeB.degree;
      b.insert(nodeB, b.end());
    }
    //cout << "Printing Polynomial B:" << endl;
    //b.printList();
    c = (List) PolynomialAdd (a, b);
    cout << "Printing Polynomial C:" << endl;
    c.printList();
    d = (List) PolynomialMult(a, b);
    cout << "Printing Product a and b:" << endl;
    d.printList();
    return 0;
}

/*-------------------------------------------------------------------------
 * $Log$
 *
 * Local Variables:
 * time-stamp-active: t
 * time-stamp-line-limit: 20
 * time-stamp-start: "Last modified:[ 	]+"
 * time-stamp-format: "%3a %02d-%3b-%:y %02H:%02M:%02S by %u"
 * time-stamp-end: "$"
 * End:
 *                        End of ListPolynomial.C
 -------------------------------------------------------------------------*/
