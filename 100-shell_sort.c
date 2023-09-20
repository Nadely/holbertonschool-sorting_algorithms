#include "sort.h"

/**
 * shell_sort - Tri un tableau d'entiers en utilisant l'algorithme de tri de Shell.
 * @array: Le tableau à trier.
 * @size: La taille du tableau.
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, jump = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (jump < size/3)
		jump = jump *3 + 1;

	for (; jump > 0; jump = (jump - 1) / 3)
	{
		for (i = jump; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= jump && array[j - jump] > tmp;
					j -= jump)
			{
				if (array[j] != array[j - jump])
					array[j] = array[j - jump];
			}
			if (array[j] != tmp)
				array[j] = tmp;

		}
		print_array(array, size);
	}
}