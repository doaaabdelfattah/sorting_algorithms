# sorting_algorithms
 0x1B. C - Sorting algorithms &amp; Big O

	/* while (start <= end)
	{
		/* Move start untill found number > pivot */
		while (array[start] > pivot)
			start--;
		/* Move end untill found number < pivot */
		while (array[end] <= pivot)
			end++;

		if (start > end)
		{
			/* Swap the current element with the element at the temporary pivot index*/
			swap_ints(&array[start], &array[end]);
			print_array(array, size);
		} */
	}
	swap_ints(&array[high], &array[end]);
	print_array(array, size);