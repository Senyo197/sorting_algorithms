#include "sort.h"

/**
*merge - Merges two sorted sub arrays into single sorted array
*@array: The original array
*@left: The left sub array
*@left_size: The size of the left sub array
*@right: The right sub array
*@right_size: The size of the right sub array
*/
void merge(int *array, int *left, size_t left_size,
int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc(sizeof(int) * (left_size + right_size));

	if (merged == NULL)
	{
		return;
	}

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];

	}

	while (i < left_size)
		merged[k++] = left[i++];

	while (i < right_size)
		merged[k++] = right[j++];

	for (k = 0; k < left_size + right_size; k++)
		array[k] = merged[k];

	free(merged);

	print_array(array, left_size + right_size);
}


/**
*merge_sort - Sorts array using the merge_sort algorythm
*@array: The array to be sorted
*@size: The size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid, left_size, right_size, i;

	if (size > 1)
	{
		mid = size / 2;
		left_size = mid;
		right_size = size - mid;

		left = malloc(left_size * sizeof(int));
		right = malloc(right_size * sizeof(int));

		if (left == NULL || right == NULL)
		{
			return;
		}

		for (i = 0; i < left_size; i++)
			left[i] = array[i];

		for (i = 0; i < right_size; i++)
			right[i] = array[mid + i];

		merge_sort(left, left_size);
		merge_sort(right, right_size);
		merge(array, left, left_size, right, right_size);

		free(left);
		free(right);
	}
}
