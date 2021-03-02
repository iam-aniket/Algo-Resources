vector<vector<int>> ans;

vector<vector<int>> traverse(TreeNode* root)
{
	levelOrderRecursive(root, ans);
	return ans;
}
void levelOrderRecursive(TreeNode* root, int depth)
{
	if (root == NULL)return;

	if (ans.size() == depth)
		ans.push_back(vector<int>());

	ans[depth].push_back(root->val);

	levelOrder(root->left, depth + 1);
	levelOrder(root->right, depth + 1);
}
