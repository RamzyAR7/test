#include "sort.h"

/**
 * selection_sort - Sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, x, pos;
	int min;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		pos = i;
		min = array[i];
		for (x = i + 1; x < size; x++)
		{
			if (min > array[x])
			{
				min = array[x];
				pos = x;
			}
		}
		array[pos] = array[i];
		array[i] = min;
		print_array(array, size);
	}
}
