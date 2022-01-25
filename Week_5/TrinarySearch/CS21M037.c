/**************************************************************************
 *  $1$
 *  File:	 CS21M037.c
 *
 *  Purpose: To check whether 5 input numbers are multiples of 5 within 0 to 95 or not.
 *
 *  Author:	CS21M037
 *
 *  Date:	30-08-2021
 *
 *  Bugs:	Will not detect as multiple of 5 if the input is not within 0 to 95.
 *
 *  Change Log:	30-08-2021 CS21M037
 *  		Added comments to explain the program.
 *      Updated code to follow the code standards.
 *
 **************************************************************************/

#include "stdio.h"

/**************************************************
 * Function            : TrinarySearch
 * Purpose             : Performs trinary search on array a for an input element d
 *                       Splits array a into three parts, checks within which part d might be present
 *                       (assuming array a is sorted) and recursively calls itself on that part
 * Input               : int a[20] - array to be searched
 *                       int b - start index
 *                       int c - end index
 *                       int d - element to be searched
 * Output              : Index of the element to be searched in the array if it is present between indices b and c
 *                       -1 if the element is not present
 *************************************************/
int TrinarySearch(int *a, int b, int c, int d)
{
    int   e, f, temp;

    temp = (c - b) / 3;                   /* (1/3)rd of gap between c (start index) and b (end index) */
    e = b + temp;                         /* index of (1/3)rd position between c (start index) and b (end index) */
    f = c - temp;                         /* index of (2/3)rd position between c (start index) and b (end index) */

    if (b < c)                            /* If b (start index) and c (end index) dont collide or cross */
    {
        if (d > a[f])                     /* If d is greater than a[f] */
        {
            b = f + 1;                    /* change start index b to index after f ((2/3)rd position) */
        }
        else if (d > a[e])                /* If d is less than / equal to a[f] and greater than a[e] */
        {
            b = e + 1;                    /* change start index b to index after e ((1/3)rd position) */
            c = f;                        /* change end index c to f ((2/3)rd position) */
        }
        else                              /* If d is less than / equal to a[e] */
            c = e;                        /* Else, change end index c to e ((1/3)rd position) */

        return (TrinarySearch(a, b, c, d));   /* Run same function with new updated start index b and end index c */
    }

    else                                  /* If b (start index) and c (end index) collide or cross */
    {
        if (a[b] == d)                    /* If d is equal to a[b] */
            return(b);                    /* Return b (start index) */
        else                              /* If not equal */
            return (-1);                  /* Return -1 */
    }
}

/**************************************************
 * Function            : main
 * Purpose             : To check whether 5 input values are multiples of 5 within 0 to 95 or not,
 *                       and if they are, prints their quotient when divided by 5, 
 *                       if not divisible or outside the range, prints -1
 * Input               : int store[5] - input elements for searching
 * Output              : prints each input along with input/5 if divisible and within 0 to 95
 *                       or else -1 in (input,output) format
 *************************************************/
int main(int argc, char **argv)
{
    int   store[5];                         /* Array to store input values */

    int   i, yo;                            /* Counter for loop and variable for storing output of function */
    int   a[20];                            /* Array to store 0, 5, 10, ... 95 - Multiples of 5 from 0*5 to 19*5 */

    for (i = 0; i < 20; i++)                /* Loop to generate multiples of 5 */
    {
        a[i] = i*5;
    }

    for (i = 0; i < 5; i++)                 /* Loop to get input values */
        scanf("%d", &store[i]);

    for (i = 0; i < 5; i++)                 /* Loop to run the search for each input */
    {
        yo = TrinarySearch(a, 0, 19, store[i]); /* Search function call from start index 0 to end index 19 */

        /* yo stores -1 if the input is not found in array a, i.e. input is not divisible by 5 or not within 0 to 95 */
        /* otherwise, yo stores the index of the input in array a which is same as quotient when input is divided by 5 */
        
        printf("(%d,%d)", store[i], yo);    /* Print output */
    }

    return 0;
}