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

	vector<vector<int>> pathSum(TreeNode* root, int targetSum)
	{
		int curSum = 0;
		vector<int> temp;

		if (root == NULL)
			return ans;

		path(root, curSum, targetSum, temp);

		return ans;
	}
	void path(TreeNode* root, int curSum, int targetSum, vector<int> temp)
	{
		if (root == NULL)
			return;

		curSum += root->val;

		temp.push_back(root->val);

		if (root->left == NULL && root->right == NULL && curSum == targetSum)
			ans.push_back(temp);

		path(root->left, curSum, targetSum, temp);
		path(root->right, curSum , targetSum, temp);
	}
};
