#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of tree, else 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += 1;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t front = 0, back = 0, i;
	binary_tree_t **queue;
	const binary_tree_t *node;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return (0);

	queue[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		node = queue[front++];
		if (node == NULL)
			break;

		queue[back++] = (binary_tree_t *)node->left;
		queue[back++] = (binary_tree_t *)node->right;
	}

	for (i = front; i < back; i++)
	{
		if (queue[i] != NULL)
		{
			free(queue);
			return (0);
		}
	}
	free(queue);
	return (1);
}
