#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check node leaf or not
 * @node: node to check
 * Return: 1 if node if leaf 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node->left == NULL && node->right == NULL ? 1 : 0);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size of the tree, 0 if tree == NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_height - finds the height of a particular node
 * @tree: the node to find the height of
 * Return: height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree:a pointer to the root node of the tree to check
 * Return: return 1 for success 0 for failure
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t right_height, left_height;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);

	if (left == NULL || right == NULL)
		return (0);

	right_height = binary_tree_height(right);
	left_height = binary_tree_height(left);

	if (right_height == left_height)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);
}
