#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: pointer on array's adress
 * @size: size of array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min_index = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[min_index])
				min_index = i;
		}

			if (min_index != i)
			{
				tmp = array[j];
				array[j] = array[min_index];
				array[min_index] = tmp;
				print_array(array, size);
			}
	}
}
