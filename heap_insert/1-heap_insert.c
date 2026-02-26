#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_values - Swap the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_up - Restore the heap property by moving the node up
 * @node: Pointer to the node to move up
 *
 * Return: node
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->parent->n < node->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * insert_into_complete_tree - Insert a new node in the first available spot
 *
 * @root: Double pointer to the root of the tree
 * @value: Value to insert
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *insert_into_complete_tree(heap_t **root, int value)
{
	binary_tree_t **queue;
	int front = 0;
	int  rear = 0;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	queue = malloc(1024 * sizeof(binary_tree_t *));
	if (!queue)
		return (NULL);
	queue[rear++] = *root;
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (current->left == NULL)
		{
			current->left = binary_tree_node(current, value);
			free(queue);
			return (current->left);
		}
		else
			queue[rear++] = current->left;

		if (current->right == NULL)
		{
			current->right = binary_tree_node(current, value);
			free(queue);
			return (current->right);
		}
		else
			queue[rear++] = current->right;
	}
	free(queue);
	return (NULL);
}

/**
 * heap_insert - Insert a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = insert_into_complete_tree(root, value);

	if (!new_node)
		return (NULL);

	new_node = heapify_up(new_node);
	return (new_node);
}
