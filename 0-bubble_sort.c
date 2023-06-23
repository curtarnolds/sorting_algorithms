#include "sort.h"


/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t curr, i;
	int temp = 0, count = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (curr = 0; curr < size - i - 1; curr++)
		{
			count++;
			if (array[curr] > array[curr + 1])
			{
				printf("count: %d\t", count);
				temp = array[curr];
				array[curr] = array[curr + 1];
				array[curr + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
