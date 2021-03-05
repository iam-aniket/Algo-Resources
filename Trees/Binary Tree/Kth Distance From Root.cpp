vector<int> kthDistanceFromRoot(TreeNode * root, int k)
{
	vector<int> ans;
	int depth = 0;
	solve(root, k, depth, ans);
	return ans;
}
void solve(TreeNode * root, int k, int depth, vector<int>& ans)
{
	if (root == NULL)
		return;

	if (depth == k)
	{
		ans.push_back(root->val);
		return;
	}

	solve(root->left, k, depth + 1, ans);
	solve(root->right, k, depth + 1, ans);
}
