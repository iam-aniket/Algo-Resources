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
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> ans;
		rightViewDFS(root, ans, 0);
		return ans;
	}
	void rightViewDFS(TreeNode* root, vector<int>& ans, int depth)
	{
		if (root == NULL)return;

		if (ans.size() == depth)
			ans.push_back(root->val);

		rightViewDFS(root->right, ans, depth + 1);
		rightViewDFS(root->left, ans, depth + 1);
	}
	void leftViewDFS(TreeNode* root, vector<int>& ans, int depth)
	{
		if (root == NULL)return;

		if (ans.size() == depth)
			ans.push_back(root->val);

		leftViewDFS(root->left, ans, depth + 1);
		leftViewDFS(root->right, ans, depth + 1);
	}

};
