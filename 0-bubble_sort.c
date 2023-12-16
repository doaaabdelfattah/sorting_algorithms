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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: head of the list
 * @size: index
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j, flag;
if (size < 2)
return;
for (i = 0; i < size - 1; i++)
{
flag = 0;
for (j = 0; j < size - 1 - i; j++)
{
if (array[j] > array[j + 1])
{
swap_ints(&array[j], &array[j + 1]);
flag = 1;
print_array(array, size);
}
}
if (flag == 0)
break;
}
}
