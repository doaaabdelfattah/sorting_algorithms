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
	/* Is size < 2 do nothing */
	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != j)
		{
			swap_ints(&array[i], &array[min]);
			flag = 1;
		}
		if (flag == 1)
			print_array(array, size);
	}
}
