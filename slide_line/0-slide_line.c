#include "slide_line.h"

/**
 * slide_left - Slides and merges an array to the left
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 *
 * Return: void
 */
void slide_left(int *line, size_t size)
{
	size_t i, j = 0;
	int temp[1024];
	size_t temp_size = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			temp[temp_size] = line[i];
			temp_size++;
		}
	}

	for (i = 0; i < temp_size; i++)
	{
		if (i < temp_size - 1 && temp[i] == temp[i + 1])
		{
			line[j] = temp[i] * 2;
			i++;
		}
		else
		{
			line[j] = temp[i];
		}
		j++;
	}

	while (j < size)
	{
		line[j] = 0;
		j++;
	}
}

/**
 * slide_right - Slides and merges an array to the right
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 *
 * Return: void
 */
void slide_right(int *line, size_t size)
{
	int i, j;
	int temp[1024];
	int temp_size = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			temp[temp_size] = line[i];
			temp_size++;
		}
	}

	j = size - 1;
	for (i = 0; i < temp_size; i++)
	{
		if (i < temp_size - 1 && temp[i] == temp[i + 1])
		{
			line[j] = temp[i] * 2;
			i++;
		}
		else
		{
			line[j] = temp[i];
		}
		j--;
	}

	while (j >= 0)
	{
		line[j] = 0;
		j--;
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to array of integers to slide & merge
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}
