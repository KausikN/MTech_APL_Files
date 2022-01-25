/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	BigIntegerAddition.C
 *
 *  Purpose:	Implementation of Addition of Large Integers using ListADT
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

/******************************************************************************
   BigInt : Takes as input two BigIntegers and returns their sum
   inputs : string1, string2
   outputs : BigIntAdd -- the sum of the two integers in another string.
******************************************************************************/

List  BigIntAdd( char *string1, char *string2) {
  List*    num1 = new List;               /* Stores the first number */
  List*    num2 = new List;               /* Stores the second number */
  List*    sumList = new List;            /* Stores the sum */

  num1->makeNull();                       /* Initialise List for string1 */
  num2->makeNull();                       /* Initialise List for string2 */
  sumList->makeNull();                    /* Initialise List for Output Sum */
    
  int       numLength1 = 0;               /* Length of number 1 without leading zeros */
  int       numLength2 = 0;               /* Length of number 2 without leading zeros */

  // Insert string1 digits into num1 (Rightmost digit is at the start of the list)
  // Example: 123 is stored as HEAD->3->2->1
  int       i = 0;                        /* Loop counter */
  int       leadingZeroCheck = 0;         /* Check if digit is leading zero */
  // Loop through string1 charecters and keep inserting digits into start of num1
  // Ignore leading zeros
  while (i < (int) strlen(string1)) {
    int digit = string1[i] - '0';         /* Convert charecter to digit */

    if (digit != 0 || leadingZeroCheck != 0 || (i == ((int) strlen(string1)-1))) {
      num1->insert(string1[i] - '0', num1->first());
      leadingZeroCheck = 1;
      numLength1++;
    }
    i++;
  }

  // Insert string2 digits into num2 (Rightmost digit is at the start of the list)
  // Example: 456 is stored as HEAD->4->5->6
  i = 0;
  leadingZeroCheck = 0;
  // Loop through string2 charecters and keep inserting digits into start of num2
  // Ignore leading zeros
  while (i < (int) strlen(string2)) {
    int digit = string2[i] - '0';         /* Convert charecter to digit */

    if (digit != 0 || leadingZeroCheck != 0 || (i == ((int) strlen(string2)-1))) {
      num2->insert(string2[i] - '0', num2->first());
      leadingZeroCheck = 1;
      numLength2++;
    }
    i++;
  }

  // Add the two number lists
  int       carry = 0;                    /* Carry while adding */
  List*     largerNum = NULL;             /* Assign the larger number list out of num1 and num2 */

  // Compare number lengths and assign the larger number list
  if (numLength2 > numLength1)
    largerNum = num2;
  else
    largerNum = num1;
  
  // Loop digit by digit in both number lists and add corresponding values
  // Stop either of the lists (smaller list) becomes empty
  while (num1->next(num1->first()) != NULL && num2->next(num2->first()) != NULL) {
    // Add the two digits along with previous carry
    int sum = num1->retrieve(num1->first()) + num2->retrieve(num2->first()) + carry;
    carry = (int) (sum / 10);             /* Calculate next carry after adding */
    sum = sum % 10;                       /* Calculate the sum digit */

    // Insert the sum digit into first position of sum list
    sumList->insert(sum, sumList->first());

    // Delete the added digits from the two lists
    num1->delItem(num1->first());
    num2->delItem(num2->first());
  }

  // Put the remaining digits from the larger number list with previous carry to sum list
  while (largerNum->next(largerNum->first()) != NULL) {
    int sum = largerNum->retrieve(largerNum->first()) + carry;
    carry = sum / 10;
    sum = sum % 10;
    sumList->insert(sum, sumList->first());

    largerNum->delItem(largerNum->first());
  }

  // Add the final carry digit if it is 1
  if (carry != 0) {
    sumList->insert(carry, sumList->first());
  }

  return *sumList;
}

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of BigIntegerAddition.C
 **************************************************************************/