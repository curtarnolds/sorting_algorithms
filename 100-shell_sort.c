#include "sort.h"


/**
 * shell_sort - Sort an array of integers using shell sort with
 * Knuth's gap sequence (n + 1 = n * 3 + 1)
 * @array: An array of integers
 * @size: The size of the array
*/
void shell_sort(int *array, size_t size)
{
	int *gaps, temp, gapIndex;
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	gaps = (int *) calloc(size, sizeof(int));
	knuth_gen(gaps, size);
	gapIndex = 0;
	while (gaps[gapIndex])
	{
		gap = gaps[gapIndex];
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		gapIndex++;
		print_array(array, size);
	}
	free(gaps);
}


/**
 * knuth_gen - Populate an array with Knuth's sequence
 * @gap_array: The gap array
 * @size: size of the array
*/
void knuth_gen(int *gap_array, size_t size)
{
    size_t gap = 1;
	int j;

    while ((gap * 3) + 1 <= size)
	{
        gap = (gap * 3) + 1;
	}

	j = 0;
    while (gap > 0)
	{
        gap_array[j] = gap;
        gap = (gap - 1) / 3;
		j++;
    }
}
