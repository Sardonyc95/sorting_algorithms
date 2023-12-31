#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Function that order a subset of an array of
 *                    integers according to the lomuto partition
 *                    scheme (last element as pivot).
 * @array: input param (The array of integers)
 * @size: input param (The size of the array)
 * @left: input param (The starting index of the subset to order)
 * @right: input param (The ending index of the subset to order)
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Function that implement the quicksort
 *               algorithm through recursion.
 * @array: input param (An array of integers to sort)
 * @size: input param (The size of the array)
 * @left: input param (The starting index of the array partition to order)
 * @right: input param (The ending index of the array partition to order)
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Function that sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: input param (An array of integers)
 * @size: input param (The size of the array)
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
