#include "sort.h"

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
	listint_t *node, *node_next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;

	while (node != NULL)
	{
		node_next = node->next;

		if (node->n < node->prev->n)
		{
			temp = node->prev;

			while (temp != NULL && node->n < temp->n)
			{
				temp->next = node->next;

				if (node->next != NULL)
					node->next->prev = temp;

				node->next = temp;
				node->prev = temp->prev;
				temp->prev = node;

				if (node->prev == NULL)
					*list = node;

				else
					node->prev->next = node;

				temp = node->prev;
				print_list(*list);
			}
		}
		node = node_next;
	}
}
