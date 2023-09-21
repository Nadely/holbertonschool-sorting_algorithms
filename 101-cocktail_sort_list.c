#include "sort.h"

/**
 * cocktail_func - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: double pointer list's adress
 *
 * Return: nothing
 */

void cocktail_func(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current = NULL;

		while (1)
	{
		swapped = 0;
		current = *list;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;

				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;
				if (current->next != NULL)
					current->next->prev = current;

				swapped = 1;

				if (current->prev == NULL)
					*list = current;

				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
		{
			break;
		}

		end = current;

		swapped = 0;

		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				if (current->prev->prev != NULL)
					current->prev->prev->next = current;
				else
					*list = current;

				current->prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = current->prev;
				current->next = current->prev;
				current->prev = current->prev->prev;
				current->next->prev = current;

				swapped = 1;

				if (current->prev == NULL)
					*list = current;

				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}

		start = current;
	}
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: double pointer list's adress
 *
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cocktail_func(list);
}
