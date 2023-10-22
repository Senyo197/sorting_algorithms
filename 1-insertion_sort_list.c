#include "sort.h"

/**
*insertion_sort_list - Sort a doubly linked list in ascending order using
*insertion sort algorythm
*@list: A pointer to pointer to the head of list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	while (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current->next;

		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}

		current = temp;
	}
}
