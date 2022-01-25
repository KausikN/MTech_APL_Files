/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	ListADT.h
 *
 *  Purpose:	Header file for implementation of List ADT
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

#ifndef LIST_ADT_H
#define LIST_ADT_H
#include <iostream>
#include "ElementType.h"
using namespace std;

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
#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of ListADT.h
 **************************************************************************/