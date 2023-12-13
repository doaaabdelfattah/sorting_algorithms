#include "sort.h"
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * insertion_sort_list - sorts doubly linked list in ascending.
 * @list: pointer to double linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted;
    listint_t *current;
    int tmp;
    if (list == NULL || list->next == NULL)
        return list;
    
    sorted = NULL;
    current = list;

    while (current != NULL)
    {
        

    }
}