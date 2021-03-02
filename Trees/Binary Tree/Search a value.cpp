TreeNode* search(TreeNode* root, int data)
{
	bool x = preorder(root, data);
	return x;
}
bool preorder(TreeNode* root, int data)
{
	if (root == NULL)return 0;

	if (root->val == data)
		return 1;

	bool temp = preorder(root->left, data);
	if (temp)
		return 1;

	bool temp2 = preorder(root->right, data);
	return temp2;
}
