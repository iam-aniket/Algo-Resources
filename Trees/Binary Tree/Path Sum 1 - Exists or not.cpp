class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		int curSum = 0;
		return sumCheck(root, curSum, targetSum);
	}
	bool sumCheck(TreeNode* root, int curSum, int sum)
	{
		if (root == NULL)
			return false;

		curSum += root->val;

		if (root->left == NULL && root->right == NULL && curSum == sum)
		{
			return true;
		}

		return sumCheck(root->left, curSum, sum) ||
		       sumCheck(root->right, curSum, sum);
	}
};
