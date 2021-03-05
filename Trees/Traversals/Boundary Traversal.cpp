//Refer Kashish Video
vector<int> boundaryTraversal(TreeNode * root)
{
	vector<int> ans;
	if (root == NULL)
		return ans;

	ans.push_back(root->val);

	if (root->left == NULL && root->right == NULL)
		return ans;

	leftBoundary(root->left, ans);
	leafNodes(root, ans);
	rightBoundary(root->right, ans);

	return ans;
}
void leftBoundary(TreeNode * root, vector<int>& ans)
{
	if (root == NULL)
		return;
	ans.push_back(root->val);
	if (root->left != NULL || root->right != NULL)
	{
		if (root->left)
			leftBoundary(root->left, ans);
		else if (root->right)
			leftBoundary(root->right, ans);
	}
}
//Preorder for leaf Nodes
void leafNodes(TreeNode * root, vector<int>& ans)
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL)
		ans.push_back(root->val);

	leafNodes(root->left, ans);
	leafNodes(root->right, ans);
}
void rightBoundary(TreeNode * root, vector<int>& ans)
{
	if (root == NULL)
		return;
	if (root->left != NULL || root->right != NULL)
	{
		if (root->right)
			leftBoundary(root->right, ans);
		if (root->left)
			leftBoundary(root->left, ans);
	}
	ans.push_back(root->val);
}
