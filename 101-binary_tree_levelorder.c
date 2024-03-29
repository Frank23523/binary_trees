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
 * binary_tree_levelorder - goes through tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t front = 0, back = 0;
	binary_tree_t **queue;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return;

	queue[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		node = queue[front++];
		func(node->n);

		if (node->left)
			queue[back++] = (binary_tree_t *)node->left;
		if (node->right)
			queue[back++] = (binary_tree_t *)node->right;
	}
	free(queue);
}
