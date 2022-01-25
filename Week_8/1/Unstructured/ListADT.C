/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	ListADT.C
 *
 *  Purpose:	Implementation of ListADT
 *
 *  Author:	CS21M037, N Kausik
 *
 *  Created:    20-09-2021
 *
 *  Last modified:  
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/

#include <iostream>
#include "ListADT.h"
#include "ElementType.h"

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

/**************************************************************************
 * $Log$
 *
 * End:
 *                        End of ListADT.C
 **************************************************************************/