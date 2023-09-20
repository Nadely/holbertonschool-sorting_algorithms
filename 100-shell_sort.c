#include "sort.h"

/**
 * knuth - Knuth sequence
 * @sequence: pointer of array of stokage
 * @size: size of an array
 * Return: nothing
 */

void knuth(int *sequence, size_t size)
{
	size_t n = 1;
	size_t idx = 0;

	while (n < size)
	{
		sequence[idx++] = n;
		n = n * 3 + 1;
	}
}

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

/**
 * shell_sort - unction that sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: pointer on array's adress
 * @size: size of array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	int knuth_sequence[size], temp;
	size_t inv, interval, i, j;
	knuth(knuth_sequence, size);

	if (array == NULL || size < 2)
		return;

	for (inv = size - 1; inv > 0; inv--)
	{
		interval = knuth_sequence[inv];

		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
	print_array(array, size);
	bubble_sort(array, size);
	print_array(array, size);
}
