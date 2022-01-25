/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	LinkArray.C - Implementation of lists using definition
 *              of List ADT in AHU.
 *
 *  Purpose:	
 *
 *  Author:	Hema A Murthy
 *
 *  Created:    Tue 12-Sep-2000 12:22:49
 *
 *  Last modified:  Sat 9-Dec-2000 17:38:13 by hema
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/
#ifndef LIST_ADT_H
#define LIST_ADT_H
#include <iostream>
#include "ElementType.h"
using namespace std;

typedef int Position;
typedef struct CellType {
    ElementType value;
    Position next;
} CellNode;


class List {
public:
    void insert(ElementType x, Position p);
    void replace(ElementType x, Position p);
    void delItem(Position p);
    ElementType retrieve(Position p);
    void makeNull();
    void printList();
    Position end();
    Position first();
    Position prev(Position p);
    Position locate(ElementType x);
    Position next(Position p);
private:
    Position lastNode;
    CellNode*    list;
};
#endif
