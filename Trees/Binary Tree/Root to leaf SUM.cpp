class Solution {
public:
	int ans = 0;

	int sumNumbers(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		int temp = 0;
		sum(root, temp);

		return ans;
	}
	void sum(TreeNode* root, int x)
	{
		x = x * 10 + root->val;

		if (root->left == NULL && root->right == NULL)
			ans += x;

		if (root->left != NULL)
			sum(root->left, x);
		if (root->right != NULL)
			sum(root->right, x);
	}
};
