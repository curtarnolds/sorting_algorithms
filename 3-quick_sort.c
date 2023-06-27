#include "sort.h"



/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the QuickSort algorithm (with Lomuto partition scheme)
 * @array: An array of integers
 * @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	int start, end;

	if (array == NULL || size < 2)
		return;

	start = 0;
	end = size - 1;
	sort_algo(array, size, start, end);
}


/**
 * lomuto_part - Divide an array into two using Lomuto partition scheme
 * @array: An array of integers
 * @start: Beginning of the array
 * @end: The end of the array
 * @size: The size of the array
 * Return: The index of the pivot
*/
size_t lomuto_part(int *array, size_t size, int start, int end)
{
	int temp_index, i, pivot;

	pivot = array[end];
	temp_index = start - 1;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			temp_index++;
			if (temp_index != i)
				swap_arr(&array[temp_index], &array[i], array, size);
		}
	}
	if (temp_index + 1 != end)
		swap_arr(&array[temp_index + 1], &array[end], array, size);
	return (temp_index + 1);
}


/**
 * swap_arr - Swap two integers
 * @first: First integer
 * @second: Second integer
 * @array: An array of integers
 * @size: The size of the array
 */
void swap_arr(int *first, int *second, const int *array, size_t size)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
	print_array(array, size);
}


/**
 * sort_algo - Algorithm to implement quick sort
 * @array: An array of integers
 * @start: Beginning of the array
 * @end: End of the array
 * @size: The size of the array
 */
void sort_algo(int *array, size_t size, int start, int end)
{
	int p_index;

	if (start >= end || start < 0)
		return;

	p_index = lomuto_part(array, size, start, end);
	if (p_index - 1 > start)
		sort_algo(array, size, start, p_index - 1);
	sort_algo(array, size, p_index + 1, end);
}
