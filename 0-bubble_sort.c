#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, x, tmp;
	int alarm = 0;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size - 1 - i; x++)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
				alarm = 1;
				print_array(array, size);
			}
		}
		if (alarm == 0)
		{
			break;
		}
	}
}
