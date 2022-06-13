#include "sort.h"
/**
 * partition - function that implements lomuto partition scheme
 * @array: array
 * @low: first el
 * @high: last el
 * @size: size of array
 * Return: index of smaller el
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * lomuto_sort - lomuto partition scheme implemented
 * @array: array
 * @low: first el
 * @high: last el
 * @size: size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high, size);

		lomuto_sort(array, low, part - 1, size);
		lomuto_sort(array, part + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
