#include "sort.h"

/**
*lomuto_partition - Lomuto partition scheme for quick sort algorythm
*@arr: Array to be sorted
*@low: Low index of the partition
*@high: High index of the partition
*@size: Size of the array
*Return: The index of the pivot element
*/
int lomuto_partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int temp, j, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, size);
			}
		}
	}

	if (i + 1 != high)
	{
		temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		print_array(arr, size);
	}

	return (i + 1);
}


/**
*recursive_quick_sort - Recursive function to perform quick sort algorythm
*@arr: Array to be sorted
*@low: Low index of the partition
*@high: High index of the partition
*@size: Size of the array
*/
void recursive_quick_sort(int *arr, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(arr, low, high, size);
		recursive_quick_sort(arr, low, pivot_index - 1, size);
		recursive_quick_sort(arr, pivot_index + 1, high, size);
	}
}


/**
*quick_sort - Sorts integers in ascending order using Quick Sort algorythm
*@array: Array to be sorted
*@size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}
