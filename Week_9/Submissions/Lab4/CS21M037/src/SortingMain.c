/**************************************************************************
 *  $1$
 *  File:    SortingMain.c
 *
 *  Purpose: Takes two arrays of integers and 
 *           prints the sorted order of array 1 using BubbleSort and 
 *           sorted order of array 2 using QuickSort
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
 *  SortAlgo -- Passing function pointers to a function
 *    Args:     array - array of integers
 *              size - size of the array
 *              Sort - function pointer to specify the sorting algorithm
 *    Returns:  void
 *    Bugs: 
 * -------------------------------------------------------------------------*/

void SortAlgo (int *array, int size, void (*Sort)()) {
    
    // Sort the array using the specified sorting algorithm in Sort argument
    (*Sort)(array, 0, size - 1);

}   /*  End of SortAlgo  */

/*-------------------------------------------------------------------------
 *  main -- Main function which prints the sorted order of array 1 using BubbleSort and 
            sorted order of array 2 using QuickSort
 *    Args:     -
 *    Inputs:   Size of array 1, Array 1, Size of array 2, Array 2
 *    Returns:  -
 *    Bugs:     -
 * -------------------------------------------------------------------------*/

int main() {
    int     n;
    int     i,j;
    int     max;
    int     *array;
    int     temp;
    void    (*Sort)();

    // printf ("number of elements:");
    scanf ("%d", &n);
    
    //Create the integer array of size n
    i = 0;
    while(i < n) {
        array[i] = 0;
        i++;
    }

    //Read the input array
    i = 0;
    while(i < n) {
        scanf ("%d", &array[i]);
        i++;
    }
    
    Sort = &BubbleSortDesc;
    SortAlgo(array, n, Sort);
    
    printf ("Bubble Sort Desc:");
    //Print the sorted(Descending) array with each element is separated by space
    i = 0;
    while(i < n) {
        printf ("%d ", array[i]);
        i++;
    }

    
    // printf ("number of elements:");
    scanf ("%d", &n);
    
    //Create the array of size n
    j = 0;
    while(j < n) {
        array[j] = 0;
        j++;
    }

    //Read the input array
    j = 0;
    while(j < n) {
        scanf ("%d", &array[j]);
        j++;
    }

    Sort = &QuickSortDesc;
    SortAlgo(array, n, Sort);
    
    printf ("Quick  Sort Desc:");
    //Print the sorted(Descending) array with each element is separated by space
    j = 0;
    while(j < n) {
        printf ("%d ", array[j]);
        j++;
    }

    return 0;
}   /*  End of main  */

/**************************************************************************
 * $Log$
 *
 *                        End of SortingMain.c
 **************************************************************************/
