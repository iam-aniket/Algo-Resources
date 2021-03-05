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
	int ans = INT_MAX;
	int minDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int d = 1;
		depth(root, d);
		return ans;
	}
	void depth(TreeNode* root, int Ad)
	{
		if (root == NULL)
			return;

		if (root-> left == NULL && root->right == NULL)
			ans = min(d, ans);

		depth(root->left, d + 1);
		depth(root->right, d + 1);
	}
};
