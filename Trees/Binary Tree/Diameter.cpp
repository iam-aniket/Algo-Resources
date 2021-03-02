int diameterOfBinaryTree(TreeNode* root)
{
	int d = 0;
	rec(root, d);
	return d;
}

int dfs(TreeNode* root, int &d)
{
	if (root == NULL) return 0;

	//left max depth
	int ld = rec(root->left, d);

	//right max depth
	int rd = rec(root->right, d);

	//d = max value of ld + rd
	d = max(d, ld + rd);

	return max(ld, rd) + 1;
}
