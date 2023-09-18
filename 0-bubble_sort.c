#include "sort.h"
/*
 * funct_rev - function for inverting two values in an array
 * @x: pointer on first value
 * @y: pointer on second value
 * Return: nothing
 */
void funct_rev(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
 * bubble_sort - function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: pointer on array
 * @size: size of array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				funct_rev(&array[j], &array[j + 1]);
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
