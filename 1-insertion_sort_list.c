#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next_node, *current_node;

	if (list == NULL || *list == NULL)
		return;

	next_node = (*list)->next;

	while (next_node != NULL)
	{
		current_node = next_node->prev;

		while (current_node != NULL && current_node->n > next_node->n)
		{
			/* Swap current and insertion_point nodes */
			if (next_node->next != NULL)
				next_node->next->prev = current_node;

			current_node->next = next_node->next;
			next_node->next = current_node;
			next_node->prev = current_node->prev;

			if (current_node->prev != NULL)
				current_node->prev->next = next_node;
			current_node->prev = next_node;

			if (next_node->prev == NULL)
				*list = next_node;

			print_list(*list);

			current_node = next_node->prev;
		}

		next_node = next_node->next;
	}
}
