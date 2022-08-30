#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: list to be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next, *key;

	if (!*list || !list || !list->next)
		return;

	key = (*list)->next;
	while (key)
	{
		next = key->next;
		while (key->prev && key->n < key->prev->n)
		{
			key->prev->next = key->next;
			if (key->next)
				key->next->prev = key->prev;
			key->next = key->prev;
			key->prev = key->next->prev;
			key->next->prev = key;
			if (key->prev)
				key->prev->next = key;
			else
				*list = key;
			print_list(*list);
		}
		key = next;
	}
}
