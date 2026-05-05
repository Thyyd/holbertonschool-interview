#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev;

	if (!list)
		return (NULL);

	express = list;
	prev = list;

	/* Step 1: Browse the express lane */
	while (express->express)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);

		if (express->n >= value)
			break;
	}

	/* Step 2: Determine the search interval */
	if (!express->express && express->n < value)
	{
		/* Value might be after the last express node */
		prev = express;
		while (express->next)
			express = express->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, express->index);
	}
	else
	{
		/* Value is between prev and express */
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, express->index);
		express = prev->express;
	}

	/* Step 3: Linear search in the interval */
	while (prev && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
