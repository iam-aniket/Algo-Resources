class Solution {
public:
	int count = 0, ans = 0;
	int rangeSumBST(TreeNode* root, int low, int high)
	{
		solve(root, low, high);
		return ans;
	}
	void solve(TreeNode* root, int low, int high)
	{
		if (root == NULL)
			return;
		if (root->val <= high && root->val >= low)
		{
			ans += root->val;
			count++;
            solve(root->left,low,high);
            solve(root->right,low,high);
		}
		else if (root->val < low)
			solve(root->right, low, high);
		else
			solve(root->left, low, high);
	}
};
