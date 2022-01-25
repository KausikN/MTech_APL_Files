/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	ListADTPtr - Implementation of lists using definition
 *              of List ADT in AHU.
 *
 *  Purpose:	
 *
 *  Author:	Hema A Murthy
 *
 *  Created:    Tue 12-Sep-2000 12:22:49
 *
 *  Last modified:  Wed 2-Sep-2020 10:31:43 by hema
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/
#include "ListADTPtr.h"
#include "ElementType.h"
#include <iostream>

void List::makeNull() {
    listHead = new CellNode;// creates a single node
    listHead->next = NULL;
}
void List::insert(ElementType x, Position p) {
    Position temp;
    temp = p->next;
    p->next = new CellType;
    p->next->next    = temp;
    p->next->value = x;
}
void List::replace(ElementType x, Position p) {
    p->next->value = x;
}
ElementType List::retrieve(Position p) {
    return(p->next->value);    
}
void List::printList() {
    Position p;
    p = listHead->next;
    while (p != NULL) {
        Print(p->value);
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

Position List::prev(Position p) {
    Position ptr;
    ptr = listHead;
    while ((ptr->next != p) || (ptr != NULL))
        ptr = ptr->next;
    return ptr;
}

Position List::locate (ElementType x) {
    Position p;
    ElementType y;
    p = listHead;
    while (p->next != NULL) {
        y = p->next->value;
        if (Compare(y, x))
            return p;
        else
            p = p->next;
    }
    return NULL;
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
 *                        End of ListADTPtr.C
 **************************************************************************/
