#include "sort.h"
/**
 * merge_func - merge subarrays
 * @array: array to be sorted
 * @b: buffer to store the sorted
 * @low: front index of the array
 * @mid: middle index of the array
 * @high: back index of the array
*/
void merge_func(int *array, int *b, size_t low, size_t mid, size_t high)
{
	size_t i, j, k;

	i = low;
	k = 0;
	j = mid;
	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low);

	printf("[right]: ");
	print_array(array + mid, high - mid);
	/* Compare two subarray and save the result in temp buffer(b)*/
	while (i < mid && j < high)
	{
		b[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];
	}
	/* if one of the halves still has elements remaining.*/
	while (j < high)
	{
		b[k] = array[j];
		j++;
		k++;
	}
	while (i < mid)
	{
		b[k] = array[i];
		i++;
		k++;
	}
	/* Copy the merged array back to the original array*/
	for (i = low, k = 0; i < high; i++)
		array[i] = b[k++];
	printf("[Done]: ");
	print_array(array + low, high - low);
}
/**
 * main_merge - merge subarrays
 * @array: array to be sorted
 * @b: buffer to store the sorted
 * @low: front index of the array
 * @high: back index of the array
*/
void main_merge(int *array, int *b, size_t low, size_t high)
{
	size_t mid;

	if (high - low > 1)
	{
		/* calculate mid using the range of the subarray*/
		mid =  low + (high - low) / 2;
		main_merge(array, b, low, mid);
		main_merge(array, b, mid, high);
		merge_func(array, b, low, mid, high);
	}
}
/**
 * merge_sort - merge subarrays
 * @array: array to be sorted
 * @size: buffer to store the sorted
*/
void merge_sort(int *array, size_t size)
{
	int *b;

	if (array == NULL || size < 2)
	return;
	/* Allocate memory for array */
	b = malloc((size) * sizeof(int));
	if (b == NULL)
		return;

	main_merge(array, b, 0, size);
	free(b);
}
