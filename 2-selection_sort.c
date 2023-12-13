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
 * selection_sort - sorts an array of integers in ascending order.
 * @array: head of the list.
 * @size: index.
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, min;
int flag;
for(i = 0; i < size - 1; i++)
{
    flag = 0;
    min = i;
    for (j = i + 1; j < size ; j++)
    {
        if (array[j] < array[min])
        {
            swap_ints(&array[j], &array[min]);
            print_array(array, size);
            flag = 1;
        }
    }
    if (flag == 0)
    break;
}
}