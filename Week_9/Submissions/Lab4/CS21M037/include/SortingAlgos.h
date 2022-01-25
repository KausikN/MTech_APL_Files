/**************************************************************************
 *  $Id$
 *  Release $Name$
 *
 *  File:	SortingAlgos.h
 *
 *  Purpose:	Header file for Implementation of Bubble Sort and Quick Sort Algorithms
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

#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

void Swap (int  *a, int *b);
void BubbleSortDesc(int *array, int start, int end);
void QuickSortDesc(int *array, int left, int right);

#endif

/**************************************************************************
 * $Log$
 * 
 * End:
 *                        End of SortingAlgos.h
 **************************************************************************/