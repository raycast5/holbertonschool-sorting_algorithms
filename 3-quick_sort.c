#include "sort.h"

/**
 * swap - swap numbers
 * @a: an int
 * @b: another int
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - finds partition position
 * @size: size of array
 * @array: array of ints;
 * @low: lower than pivot
 * @high: higher than pivot
 * Return: an int
 */

int partition(int array[], size_t size, int low, int high)
{

	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);
		}
	}
return (i);
}

/**
 * quickSort - sorts array using quick sort
 * @array: integer array to sort
 * @size: size of the array
 * @low: highest index
 * @high: lowest index
 * Return: Nothing
 */

void quickSort(int array[], size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		quickSort(array, size, low, pi - 1);
		quickSort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - function to call quickSort
 * @array: integer array to sort
 * @size: size of the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	quickSort(array, size, 0, size - 1);
}
