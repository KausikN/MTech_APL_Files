/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	Application.C
 *
 *  Purpose:	Application for addind large integers numbers using ListADT
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
#include "string.h"
#include "BigIntAdd.h"
#include "ListADT.h"
#include "ElementType.h"

int main(){
  char string1[101], string2[101];
  int tcs;
  cin>>tcs;
  List result;

  for(int i=0;i<tcs;i++){
    cin >> string1;
    cin >> string2;
    cout<<string1<<" + "<<string2<<" = ";
    result = (List) BigIntAdd (string1, string2);    
    result.printList();    
  }

  return 0;
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of Application.C
 **************************************************************************/