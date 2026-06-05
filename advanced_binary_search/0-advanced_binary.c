#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches value in a sorted array
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary index
 * @right: Right boundary index
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;
	int result;

	if (left > right)
		return (-1);

	print_array(array + left, right - left + 1);

	if (left == right)
	{
		if (array[left] == value)
			return ((int)left);
		return (-1);
	}

	mid = left + (right - left) / 2;

	if (array[mid] >= value)
	{
		/* Value is at mid or to the left, search left half first */
		if (mid > left)
		{
			result = advanced_binary_recursive(array, left, mid, value);
			if (result != -1)
				return (result);
		}
		/* If left half didn't have it, mid is the first occurrence */
		if (array[mid] == value)
			return ((int)mid);
	}
	else
	{
		/* Value is to the right, search right half */
		return (advanced_binary_recursive(array, mid + 1, right, value));
	}

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
