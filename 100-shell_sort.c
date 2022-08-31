#include "sort.h"

/**
 * shell_sort - sorts array in ascending order
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t inner, outer, inc = 1, i = 0;
	int temp;

	if (!array || !size || size < 2)
		return;

	while (inc <= size / 3)
	{
		inc = inc * 3 + 1;
	}
	while (inc > 0)
	{
		for (outer = inc; outer < size; outer++)
		{
			temp = array[outer];
			inner = outer;

			while (inner > inc - 1 && array[inner - inc] >= temp)
			{
				array[inner] = array[inner - inc];
				inner -= inc;
			}
			array[inner] = temp;
		}
		inc = (inc - 1) / 3;
		print_array(array, size);
		i++;
	}
}
