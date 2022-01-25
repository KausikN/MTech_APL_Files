/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	ListADTArray.C - Implementation of lists using an Array
 *
 *  Purpose:	
 *
 *  Author:	Hema A Murthy
 *
 *  Created:    Tue 12-Sep-2000 12:22:49
 *
 *  Last modified:  Wed 2-Sep-2020 10:35:37 by hema
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/
#include "ListADTArray.h"
#include "ElementType.h"
#include <iostream>
void List::makeNull() {
  list = new CellNode[100]; 
  lastNode = 0;
}
void List::insert(ElementType x, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p].value = x;
  lastNode++;
}
void List::replace(ElementType x, Position p) {
  list[p].value = x;
}
void List::printList() {
  Position p;
  p = 1;
  while (p <= lastNode) {
    Print (list[p].value);
    p++;
  }
  cout << "\n";
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
Position List::prev(Position p) {
  return (p-1);
}
Position List::locate (ElementType x) {
  int flag;
  Position p;
  CellNode y;
  p = 1;
  while (p <= lastNode) {
    y = list[p];
    if (Compare(y.value, x))
      return p;
    else
      p++;
  }
  return 0;
}
ElementType List::retrieve(Position p) {
  return (list[p].value);
}

/**************************************************************************
 * $Log$
 *
 * Local Variables:
 * time-stamp-active: t
 * time-stamp-line-limit: 20
 * time-stamp-start: "Last modified:[ 	]+"
 * time-stamp-format: "%3a %:d-%3b-%:y %02H:%02M:%02S by %u"
 * time-stamp-end: "$"
 * End:
 *                        End of ListADTArray.C
 **************************************************************************/
