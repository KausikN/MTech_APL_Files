/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	ElementType.C
 *
 *  Purpose:	Integer ElementType
 *
 *  Author:	CS21M037, N Kausik
 *
 *  Created:    20-09-2021
 *
 *  Last modified: 
 *
 *  Bugs:	
 *
 *  Change Log:	
 *  
 *
 **************************************************************************/

#include "../include/ElementType.h"

void Print (elementType x) {
    cout << x << endl;
}
int Compare (elementType x, elementType y) {
    if (x == y)
        return 1;
    else
        return 0;
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of ElementType.C
 **************************************************************************/