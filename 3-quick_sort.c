#include "sort.h"


size_t lomuto_part(int *array, size_t size, size_t start, size_t end);
void swap(int *first, int *second, const int *array, size_t size);
void sort_algo(int *array, size_t size, int start, int end);
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
size_t lomuto_part(int *array, size_t size, size_t start, size_t end)
{
	size_t temp_index, i;
	int pivot;

	pivot = array[end];
	temp_index = start - 1;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			temp_index++;
			swap(&array[temp_index], &array[i], array, size);
		}
	}
	swap(&array[temp_index + 1], &array[end], array, size);
	return (temp_index + 1);
}


/**
 * swap - Swap two integers
 * @first: First integer
 * @second: Second integer
 * @array: An array of integers
 * @size: The size of the array
 */
void swap(int *first, int *second, const int *array, size_t size)
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
	size_t p_index;

	if (start < end)
	{
		p_index = lomuto_part(array, size, 0, end);
		sort_algo(array, size, start, p_index - 1);
		sort_algo(array, size, p_index + 1, end);
	}
}
