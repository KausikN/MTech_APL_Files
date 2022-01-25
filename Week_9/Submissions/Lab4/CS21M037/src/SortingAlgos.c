/**************************************************************************
 *  $1$
 *  File:    SortingAlgos.c
 *
 *  Purpose: Bubble Sort and Quick Sort Algorithms
 *
 *  Author:  CS21M037
 *
 *  Date:    06-09-2021
 *
 *  Bugs:   Will work only if values given in arrays are within range of 'int' datatype
 *
 *  Change Log:  06-09-2021 CS21M037
 *          Updated code and comments
 *
 **************************************************************************/


#include <stdio.h>
#include "stdlib.h"
#include "../include/SortingAlgos.h"

/*-------------------------------------------------------------------------
 *  Swap -- Swaps two int elements
 *    Args:     a - pointer to integer input 1
 *              b - pointer to integer input 2
 *    Returns:  void
 *    Throws:   -
 *    See:      -
 *    Bugs:     -
 -------------------------------------------------------------------------*/

void Swap (int  *a, int *b) {
    
    int temp = *b;
    *b = *a;
    *a = temp;
  
}   /*  End of Swap */

/*-------------------------------------------------------------------------
 *  BubbleSortDesc -- Performs BubbleSort on a array of integers from given start index to end index
 *                    to sort the array in descending order   
 *    Args:     array - array of integers
 *              start - start index of the array
 *              end - end index of the array
 *    Returns:  void
 *    Bugs:     -
 * -------------------------------------------------------------------------*/

void BubbleSortDesc(int *array, int start, int end)
{
    int     i = start;
    int     j;
    int     temp;

    // Traverse through the complete array and find minimum value in each iteration with iterating varible i
    while (i < end + 1) {
        
        j = 0;
        // Traverse through the array with loop variable j and last i elements are already in place 
        while (j < end - i) {
            //Swap the elements as required
            if (array[j] < array[j+1]) {
                Swap(&array[j], &array[j+1]);
            }
            j++;
        }
        i++;
    }
  
}   /*  End of BubbleSortDesc */

/*-------------------------------------------------------------------------
 *  QuickSortDesc -- Recursive sort using CAR Hoare's Algorithm, sorts array in descending order inplace
 *    Args:    array - array of integers
 *             left - left / start index
 *             right - right / end index
 *    Returns:  void
 *    Throws:   -
 *    See:      -
 *    Bugs:     Will work only if values given in arrays are within range of 'int' datatype
 -------------------------------------------------------------------------*/

void QuickSortDesc(int *array, int left, int right) {
    int     i, j;
    int     x;
    int     pivotIndex;

    i = left;
    j = right;

    pivotIndex = (left + right) / 2;
    x = array[pivotIndex];

    //Loop to rearrange elements across pivot
    do {
        //Traverse the array from starting index until finding an element at index(i) which is smaller than Pivot element
        while (i < right && array[i] > x) {
            i++;
        }

        //Traverse the array from ending index until finding an element at index(j) which is greater than Pivot element
        while (j > left && array[j] < x) {
            j--;
        }

        // Swap the elements if required and proceed with the remaining input array
        if (i <= j) {
            Swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }   while (i <= j);

    // Recur on subarray containing elements from left to j
    if (left < j) {
        QuickSortDesc(array, left, j);
    }
    // Recur on subarray containing elements from i to right
    if (i < right) {
        QuickSortDesc(array, i, right);
    }
}   /*  End of QuickSortDesc  */

/**************************************************************************
 * $Log$
 *
 *                        End of SortingAlgos.c
 **************************************************************************/
