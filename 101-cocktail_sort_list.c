#include "sort.h"

/**
 * swap - function that reverse value
 *
 * @head: double pointer head's adress
 * @node1: pointer node1's adress
 * @node2: pointer node1's adress
 *
 * Return: nothing
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev, *temp_next;

	if (node1 == NULL || node2 == NULL || *head == NULL)
		return;

	temp_prev = node1->prev;
	temp_next = node2->next;

	if (temp_prev != NULL)
		temp_prev->next = node2;
	if (temp_next != NULL)
		temp_next->prev = node1;

	node1->next = temp_next;
	node1->prev = node2;

	node2->next = node1;
	node2->prev = temp_prev;

	if (*head == node1)
		*head = node2;
	else if (*head == node2)
		*head = node1;
	print_list(*head);
}

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
				swap(list, current, current->next);
				swapped = 1;
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
				swap(list, current->prev, current);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		start = current;
	}
	while (swapped);
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
