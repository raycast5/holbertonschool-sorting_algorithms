#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list - list to be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (!*list || !list)
		return;

	current = *list;
	while (current->next)
	{
		current = current->next;
		key = current;
		while (key->n < key->prev->n && key->prev)
		{
			key->prev->next = key->next;
			if(key->next)
				key->next->prev = key->prev;
			key->next = key->prev;
			key->prev = key->prev->prev;
			if(key->prev)
				key->prev->next = key;
			key->next->prev = key;
			if(!key->prev)
				*list = key;
			print_list(*list);
		}
	}
}
