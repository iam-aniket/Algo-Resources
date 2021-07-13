struct TreeNode
{
	int val;
	TreeNode* left, right;
}
vector<int> ans;
vector<int> diagonalTraversal(TreeNode * root)
{
	map<int, vector<int>> m;
	vector<vector<int>> ans;

	solve(root, 0, m);

	for (auto x : m)
		ans.pb(x);
	return ans;
}
void solve(TreeNode * root, int depth, map<int, vector<int>>& m)
{
	if (root == NULL)
		return;

	m[depth].push_back(root->val);

	solve(root->left, depth + 1, m);
	solve(root->right, depth, m);
}
