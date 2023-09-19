#include "sort.h"


size_t partition(int array[], size_t size);
void print_sort(int array[], size_t size, int init);
void swap(int *a, int *b);

/**
 * quick_sort - Trie un tableau d'entiers en utilisant l'algorithme Quick Sort.
 *
 * @array: Le tableau d'entiers à trier.
 * @size: La taille du tableau.
 */

void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (array == NULL|| size < 2)
		return;

	print_sort(array, size, 1);

	/* partition and get pivot index */
	pivot = partition(array, size);

	/* repeat for left of index */
	quick_sort(array, pivot);
	/* repeat for index and right */
	quick_sort(array + pivot, size - pivot);
}

/**
 * swap - Échange deux entiers.
 *
 * @a: Pointeur vers le premier entier.
 * @b: Pointeur vers le second entier.
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * partition - Partitionne un tableau autour d'un pivot et renvoie l'index
 * du pivot.
 *
 * @array: Le tableau d'entiers à partitionner.
 * @size: La taille du tableau.
 *
 * Return: L'index du pivot.
 */

size_t partition(int array[], size_t size)
{
	int pivot;
	size_t i = -1;
	size_t j;

	if (array == NULL || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i + 1);
}

/**
 * print_sort - Affiche le tableau (si init vaut 1) ou l'appelle pour affichage
 * (si init vaut 0).
 *
 * @array: Le tableau d'entiers à afficher.
 * @size: La taille du tableau.
 * @init: Indique si c'est la première fois qu'on appelle la fonction (1) ou
 * non (0).
 */

void print_sort(int array[], size_t size, int init)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && init)
	{
		p = array;
		s = size;
	}
	if (!init)
		print_array(p, s);
}
