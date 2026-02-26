#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 1 if it is a palindrome, 0 if it is not
 */

int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int i = 0, j = 0;
	int array[5120];

	if (*head == NULL)
		return (1);

	while(current != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}
	i--;
	while(j < i)
	{
		if (array[j] != array[i])
			return (0);
		j++;
		i--;
	}
	return (1);
}