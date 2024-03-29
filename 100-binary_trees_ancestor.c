#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp1 = first, *temp2 = second;
	size_t depth1 = 0, depth2 = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	while (temp1->parent)
	{
		temp1 = temp1->parent;
		depth1++;
	}

	while (temp2->parent != NULL)
	{
		temp2 = temp2->parent;
		depth2++;
	}

	temp1 = first;
	temp2 = second;
	while (depth1 > depth2)
	{
		temp1 = temp1->parent;
		depth1--;
	}
	while (depth2 > depth1)
	{
		temp2 = temp2->parent;
		depth2--;
	}

	while (temp1 && temp2)
	{
		if (temp1 == temp2)
			return ((binary_tree_t *)temp1);
		temp1 = temp1->parent;
		temp2 = temp2->parent;
	}

	return (NULL);
}
