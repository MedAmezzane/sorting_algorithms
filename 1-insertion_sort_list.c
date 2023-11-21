#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion Sort algorithm.
 * @list: A pointer to the head of the doubly linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;

	if (!list || !(*list))
		return;

	current_node = *list;

	while (current_node)
	{
		listint_t *inner_node = current_node;

		while (inner_node->prev && inner_node->n < inner_node->prev->n)
		{
			/* Swap entire nodes */
			listint_t *prev_node = inner_node->prev;
			listint_t *next_node = inner_node->next;

			if (prev_node->prev)
				prev_node->prev->next = inner_node;

			inner_node->prev = prev_node->prev;
			inner_node->next = prev_node;

			prev_node->prev = inner_node;
			prev_node->next = next_node;

			if (next_node)
				next_node->prev = prev_node;

			if (!inner_node->prev)
				*list = inner_node;

			print_list(*list);
		}

		current_node = current_node->next;
	}
}
