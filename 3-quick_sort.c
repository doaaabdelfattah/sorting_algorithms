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
 * partition - Divides array into two locationitions
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
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[i + 1] > pivot)
	{
	swap_ints(&array[i + 1], &array[high]);
	print_array(array, size);
	}
	return (i + 1);
}
/**
 * lumoto_sort - quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
*/
void lumoto_sort(int *array, size_t size, int left, int right)
{
	int location;

	if (right - left > 0)
	{
		/* locationition array and get the pivot index */
		location = partition(array, size, left, right);
		/* Sort the two partition */
		lumoto_sort(array, size, left, location - 1);
		lumoto_sort(array, size, location + 1, right);
	}
}
/**
 * quick_sort - sort array using quick sort alorithm
 * @array: pointer to array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lumoto_sort(array, size, 0, size - 1);
}
