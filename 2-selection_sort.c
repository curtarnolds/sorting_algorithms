#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * selection sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, minimum_index;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		minimum_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum_index])
			{
				minimum_index = j;
			}
		}

		temp = array[i];
		array[i] = array[minimum_index];
		array[minimum_index] = temp;

		if (minimum_index != i)
		{
			print_array(array, size);
		}
	}
}
