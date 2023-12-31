#include "sort.h"

/**
 * swap_ints - Function that swap two integers in an array.
 * @a: input param (The first integer to swap)
 * @b: input param (The second integer to swap)
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Function that sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: input param (An array of integers)
 * @size: input param (The size of the array)
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
