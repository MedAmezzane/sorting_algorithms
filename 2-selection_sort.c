#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index, temp, swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		swapped = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
				swapped = 1;
			}
		}

		if (swapped == 1)
		{
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;

			print_array(array, size);
		}
	}
}
