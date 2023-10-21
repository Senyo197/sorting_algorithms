#include "sort.h"

/**
*bubble_sort - A function to sort using the bubble sort algorythm
*@array: The pointer to the array to be stored
*@size: The size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swp = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swp = 1;
				print_array(array, size);
			}
		}

		if (swp == 0)
			break;
	}
}
