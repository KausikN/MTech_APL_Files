/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	ElementType.h - User Defined ElementType
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

typedef int ElementType; 
int Compare (ElementType x, ElementType y);
void Print (ElementType x);
#endif
