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
#ifndef ELEMENTYPE_H
#define ELEMENTYPE_H
#include <iostream>
using namespace std;

typedef struct ElementType {
  int coefft;
  int degree;
} PolyNode;

void Print (ElementType x);
int Compare (ElementType x, ElementType y);
#endif
