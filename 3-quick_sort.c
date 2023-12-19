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
 * partition - Divides array into two partitions
 * @array: array
 * @low: lower bound (left side)
 * @high: upper bound (right side)
 * @size: size of array
 * Return: index of pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, j, i;

	/* Choose the last element as the pivot*/
	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			print_array(array, size);
			swap_ints(&array[i], &array[j]);
			
		}
	}
	print_array(array, size);
	swap_ints(&array[i + 1], &array[high]);
	
	return (i + 1);
}
/**
 * quick_sort - sort array using quick sort alorithm
 * @array: pointer to array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int low, high, location;

	low = 0;
	high = size - 1;
	if (low < high)
	{
		/* Partition array and get the pivot index */
		location = partition(array, size, low, high);
		/* Sort the two partitions */
		quick_sort(array, (location));
		quick_sort(array + location + 1, (size - location - 1));
	}
}