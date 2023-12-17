

#include "sort.h"
/**
 * swap_dlnodes - swap double linked nodes.
 * @h: head of the list
 * @n1: node 1
 * @n2: node2
 */
void swap_dlnodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* step 1: Update first node*/
	(*n1)->next = n2->next;
	/* if the adjacent node of the first node isn't the end node */
	if (n2->next != NULL)
		n2->next->prev = (*n1); /* update the previous pointer */
	/* Step 2: Update Second node*/
	n2->prev = (*n1)->prev;
	n2->next = (*n1);

	/* Check if the prev is head*/
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		(*h) = n2;

	/* Updates the 'prev' pointer of the first node to point to the second node.*/
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * insertion_sort_list - sorts doubly linked list in ascending.
 * @list: pointer to double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted;
	listint_t *current;
	listint_t *tmp;
	/* if zero or one element in list*/
	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
		return;
	/* sorted is the sorted part */
	/* current is the iterable pointer. */
	sorted = (*list);
	/* move current to next node */
	current = sorted->next;

	while (current != NULL)
	{
		tmp = current->next;
		sorted = current->prev;
		/* sorted = (*list);*/
		while (sorted != NULL && sorted->n > current->n)
		{
			/* Swap */
			swap_dlnodes(list, &sorted, current);
			print_list((const listint_t *)*list);
		}
		current = tmp;
	}
}
