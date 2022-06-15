#include "sort.h"
/**
 * merge_array - merge the sub arrays
 * @array: array
 * @left: left side of array
 * @mid: mid of the array
 * @right: right side of the array
 */
void merge_array(int *array, int left, int mid, int right)
{
	int i, j, k, left_len, right_len;
	int *temp_left, *temp_right;

	left_len = mid - left + 1;
	right_len = right - mid;
	temp_left = malloc(left_len * sizeof(int));
	temp_right = malloc(right_len * sizeof(int));

	for (i = 0; i < left_len; i++)
		temp_left[i] = array[left + i];
	for (j = 0; j < right_len; j++)
		temp_right[j] = array[mid + 1 + j];
	j = 0, i = 0, k = left;
	while (i < left_len && j < right_len)
	{
		if (temp_left[i] <= temp_right[j])
		{
			array[k] = temp_left[i];
			i++;
		}
		else
		{
			array[k] = temp_right[j];
			j++;
		}
		k++;
	}
	while (i < left_len)
	{
		array[k] = temp_left[i];
		i++;
		k++;
	}
	while (j < right_len)
	{
		array[k] = temp_right[j];
		j++;
		k++;
	}
}
/**
 * merge_recursion - sorts the sub arrays
 * @array: array
 * @left: left side of array
 * @right: right side of the array
 */
void merge_recursion(int *array, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_recursion(array, left, mid);
		merge_recursion(array, mid + 1, right);
		merge_array(array, left, mid, right);
	}
}
/**
 * merge_sort - sorts an array of integers in ascending order using
 * merge sort algorithm
 * @array: array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_recursion(array, 0, size - 1);
}
