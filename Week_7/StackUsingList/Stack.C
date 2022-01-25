/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	Stack.C - Implementation of stack using List ADT
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
#include "Stack.h"
#include "ElementType.h"
#include <iostream>
void Stack::makeNull() {
    stack = new List;
    stackTop = 0;
}
void Stack::push(ElementType x) {
    stack->insert(x, stack->next(stackTop));
    stackTop = stack->next(stackTop);
}
ElementType Stack::top() {
    return stack->retrieve(stackTop);
}
ElementType Stack::pop() {
    ElementType topElement = stack->retrieve(stackTop);
    stack->delItem(stackTop);
    stackTop = stack->prev(stackTop);
    return(topElement);
}
int Stack::empty() {
    return (stackTop == 0);
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
 *                        End of Stack.C
 **************************************************************************/
