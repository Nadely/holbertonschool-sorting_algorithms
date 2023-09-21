#include "sort.h"

/**
 * swap_nodes - Échange deux nœuds dans une liste doublement chaînée
 * @list: double pointeur vers la liste
 * @current: nœud actuel
 * Return: 1 si les nœuds ont été échangés, sinon 0
 */
int swap_nodes(listint_t **list, listint_t *current)
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

		return (1);
	}
	return (0);
}

/**
 * cocktail_forward - Trie une liste doublement chaînée dans l'ordre
 * croissant de gauche à droite
 * @list: double pointeur vers la liste
 */
void cocktail_forward(listint_t **list)
{
	int swapped = 1;
	listint_t *end = NULL;
	listint_t *current = NULL;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != end)
		{
			if (swap_nodes(list, current))
			{
				swapped = 1;
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
			}
			else
				current = current->next;
		}
		end = current;
	}
}

/**
 * cocktail_backward - Trie une liste doublement chaînée dans l'ordre
 * croissant de droite à gauche
 * @list: double pointeur vers la liste
 */
void cocktail_backward(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *current = NULL;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->prev != start)
		{
			if (swap_nodes(list, current))
			{
				swapped = 1;
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	}
}

/**
 * cocktail_sort_list - Trie une liste doublement chaînée dans l'ordre
 * croissant en utilisant l'algorithme de tri à bulles bidirectionnel
 * @list: double pointeur vers la liste
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cocktail_forward(list);
	cocktail_backward(list);
}
