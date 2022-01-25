/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	Stack.C - Implementation of stack using List ADT.
 *
 *  Purpose:	
 *
 *  Author:	N Kausik
 *
 *  Created:    
 *
 *  Last modified:  
 *
 *  Bugs:	
 *
 *  Change Log:	<Date> <Author>
 *  		<Changes>
 *
 **************************************************************************/
#ifndef STACK_ADT_H
#define STACK_ADT_H
#include <iostream>
#include "ListADTArray.h"
#include "ElementType.h"
using namespace std;

class Stack {
public:
    void makeNull();
    void push(ElementType x);
    ElementType top();
    ElementType pop();
    int empty();
private:
    Position stackTop;
    List*     stack;
};
#endif
