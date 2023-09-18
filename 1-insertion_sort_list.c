#include "sort.h"

/**
 * funct_rev_bis - function for inverting two values in an array
 * @x: pointer on first value
 * @y: pointer on second value
 * Return: nothing
 */
void funct_rev_bis(const int *x, const int *y)
{
	int temp = *x;
	*(int *)x = *y;
	*(int *)y = temp;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: double pointer list's adress
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if ((*list) == NULL || list == NULL)
		return;

	node = *list;

	while (node->next != NULL)
	{
		if (node->next != NULL && node->n > node->next->n)
		{
			funct_rev_bis(&(node->n), &(node->next->n));
			print_list(*list);

			while (node->prev != NULL && node->n < node->prev->n)
			{
				funct_rev_bis(&(node->n), &(node->prev->n));
				node = node->prev;
				print_list(*list);
			}
		}
		else
		{
			node = node->next;
		}
	}
}
