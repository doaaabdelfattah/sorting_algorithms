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
	i = low - 1 ; /* Index of Temporary pivot index */
	for (j = low; j <= high - 1; j++)
	{
		/* If the current element is less than or equal to the pivot*/
		if (array[j] < pivot)
		{
		/* Move the temporary pivot index forward */
		i++;
		/* swap the current element with the element at the temporary pivot index*/
		if (array[i] != array[j])
			{
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
			}
		}
	}
	/* Move the pivot element to the correct pivot position */
	/* (between the smaller and larger elements) */
	swap_ints(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}
/**
 * lumoto_sort - quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @low: Left side
 * @high: Right side
*/
void lumoto_sort(int *array, size_t size, int low, int high)
{
	int location;

	if (high - low > 0)
	{
		/* partition the array and get the pivot index */
		location = partition(array, size, low, high);
		/* Sort the two partition */
		lumoto_sort(array, size, low, location - 1);
		lumoto_sort(array, size, location + 1, high);
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
