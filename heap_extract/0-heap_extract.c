#include "binary_trees.h"
#include <stdlib.h>

/**
 * get_node_count - Counts nodes in binary tree
 * @root: Pointer to root
 * Return: Number of nodes
 */
int get_node_count(heap_t *root)
{
    if (!root)
        return (0);
    return (1 + get_node_count(root->left) + get_node_count(root->right));
}

/**
 * get_last_node - Gets last level-order node
 * @root: Pointer to root
 * @index: Current index
 * @count: Total node count
 * Return: Pointer to last node
 */
heap_t *get_last_node(heap_t *root, int index, int count)
{
    heap_t *left, *right;

    if (!root)
        return (NULL);
    if (index == count)
        return (root);

    left = get_last_node(root->left, 2 * index, count);
    if (left)
        return (left);
    right = get_last_node(root->right, 2 * index + 1, count);
    return (right);
}

/**
 * heapify_down - Rebuilds max heap from top
 * @root: Pointer to root
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    int temp;

    if (!root)
        return;

    /* Find largest among root, left child, right child */
    if (root->left && root->left->n > largest->n)
        largest = root->left;
    if (root->right && root->right->n > largest->n)
        largest = root->right;

    /* If largest is not root, swap and continue heapifying */
    if (largest != root)
    {
        temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extracts root node of Max Binary Heap
 * @root: Double pointer to root
 * Return: Value stored in root, or 0 if failed
 */
int heap_extract(heap_t **root)
{
    int value, count;
    heap_t *last_node;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    count = get_node_count(*root);

    /* If only one node, just free it */
    if (count == 1)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    /* Find last level-order node */
    last_node = get_last_node(*root, 1, count);

    /* Replace root value with last node value */
    (*root)->n = last_node->n;

    /* Remove last node from tree */
    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }
    free(last_node);

    /* Rebuild heap */
    heapify_down(*root);

    return (value);
}
