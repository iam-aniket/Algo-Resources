TreeNode* findMin(TreeNode* node)
{
	while (node->left != NULL)
		node = node->left;

	return node;
}
TreeNode* findMax(TreeNode* node)
{
	while (node->right != NULL)
		node = node->right;

	return node;
}
