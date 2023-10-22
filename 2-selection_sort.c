#include "sort.h"

/**
*selection_sort - Sorting arrays in ascending oder using selection
* sort algorythm
*@array: Array to be sorted
*@size: The size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = 1;

		for (j = 1 + i; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size)
		}
	}
}
