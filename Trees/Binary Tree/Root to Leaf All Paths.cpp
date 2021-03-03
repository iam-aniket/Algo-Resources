class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> ans;

		if (root == NULL)
			return ans;

		string temp = to_string(root->val);

		path(root, temp, ans);

		return ans;
	}
	void path(TreeNode* root, string temp, std::vector<string>& ans)
	{
		if (root == NULL)
			return;

		if (root->left == NULL && root->right == NULL)
		{
			ans.push_back(temp);
			return;
		}

		if (root->left != NULL)
			path(root->left, temp + "->" + to_string(root->left->val), ans);

		if (root->right != NULL)
			path(root->right, temp + "->" + to_string(root->right->val), ans);
	}
