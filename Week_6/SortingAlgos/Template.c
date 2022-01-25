/**************************************************************************
 *  $Id$
 *  File:   
 *
 *  Purpose:    
 *
 *  Author: 
 *
 *  Date:   
 *
 *  Bugs:   
 *
 *  Change Log: <Date> <Author>
 *          <Changes>
 *
 **************************************************************************/


#include <stdio.h>
#include "stdlib.h"

/*-------------------------------------------------------------------------
 *  BubbleSortDesc -- 
 *    Args: 
 *    Returns: 
 *    Bugs: 
 * -------------------------------------------------------------------------*/

void BubbleSortDesc(int *array, int start, int end)
{
    int i = start, j;
    int temp;

    // Traverse through the complete array and find minimum value in each iteration with iterating varible i
    while (/*Write appropriate condition here*/) {
        
        j = 0;
        // Traverse through the array with loop variable j and last i elements are already in place 
        while (/*Write appropriate condition here*/) {
            
            //Swap the elements as required
            if (/*Write appropriate condition here*/) {
                
                /*Write the code to swap elements */
            }
            j++;
        }
        i++;
    }
  
}   /*  End of BubbleSortDesc */

/*-------------------------------------------------------------------------
 *  Swap -- Swaps two int elements
 *    Args: 
 *    Returns:  
 *    Throws:   
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/

void Swap (int  *a, int *b) {
    
    /* write your code here */
  
}   /*  End of Swap */

/*-------------------------------------------------------------------------
 *  QuickSortDesc -- Recursive sort using CAR Hoare's Algorithm, sorts array in ascending order inplace
 *    Args: 
 *    Returns:  
 *    Throws:   
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/

void QuickSortDesc(int *array, int left, int right) {
    int i, j;
    int x;

    i = //Assign i as starting index of the array
    j = //Assign j as ending index of the array

    x = //Assign middle element of the array as Pivot element x

    //Loop to rearrange elements across pivot
    do {
        //Traverse the array from starting index until finding an element at index(i) which is smaller than Pivot element
        while (/*write appropriate condition here*/) {

        /* Write your code here*/
        }

        //Traverse the array from ending index until finding an element at index(j) which is greater than Pivot element
        while (/*write appropriate condition here*/) {

        /* Write your code here*/
        }

        // Swap the elements if required and proceed with the remaining input array
        if (/*write appropriate condition here*/) {

            /* Write your code here */
        }
    }   while (/*write appropriate arguments here*/);

    // Recur on subarray containing elements that are smaller than the pivot
    if (/*write appropriate arguments here*/)
        QuickSortDesc(/*write appropriate arguments here*/);

    // Recur on subarray containing elements that are greater than the pivot
    if (/*write appropriate arguments here*/)
        QuickSortDesc(/*write appripriate arguments here*/);

}   /*  End of QuickSortDesc  */

/*-------------------------------------------------------------------------
 *  SortAlgo -- Passing function pointers to a function
 *    Args: 
 *    Returns:  
 *    Bugs: 
 * -------------------------------------------------------------------------*/

void SortAlgo ( /*write porper arguments here*/) {
    
    /* Write your code here*/

}   /*  End of SortAlgo  */

/*-------------------------------------------------------------------------
 *  main -- Main function
 *    Args: 
 *    Returns:  
 *    Bugs: 
 * -------------------------------------------------------------------------*/

int main() {
    int n;
    int i,j;
    int max;
    int *array;
    int temp;
    void (*Sort)();

    printf ("number of elements:");
    scanf ("%d", &n);
    
    //Create the integer array of size n

    //Read the input array
    
    /*Write your code to make a function call to Bubble sort using function pointers with the help of SortAlgo function*/
    
    printf ("Bubble Sort Desc:");
    //Print the sorted(Descending) array with each element is separated by space
    
    
    printf ("number of elements:");
    scanf ("%d", &n);
    
    //Create the array of size n

    //Read the input array

    /*Write your code to make a function call to QuickSort using function pointers with the help of SortAlgo function*/
    
    printf ("Quick  Sort Desc:");
    //Print the sorted(Descending) array with each element is separated by space

    return 0;
}   /*  End of main  */

/**************************************************************************
 * $Log$
 *
 *                        End of .c
 **************************************************************************/
