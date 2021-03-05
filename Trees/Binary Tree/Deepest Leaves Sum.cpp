/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> ans;

	int deepestLeavesSum(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		int depth = 0;

		path(root, depth);

		int sum = 0, i = ans.size();

		for (int j = 0; j < ans[i - 1].size(); j++)
			sum += ans[i - 1][j];

		return sum;
	}
	void path(TreeNode* root, int depth)
	{
		if (root == NULL)
			return;

		if (ans.size() == depth)
			ans.push_back(vector<int>());

		ans[depth].push_back(root->val);

		path(root->left, depth + 1);
		path(root->right, depth + 1);
	}
};
