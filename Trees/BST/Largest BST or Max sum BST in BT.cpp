class Solution
{
public:
	int ans;
	int maxSumBST(TreeNode* root) {
		ans = 0;
		findansSum(root);
		return ans;
	}

	//int[]{isBST(0/1), largest, smallest, sum}
	vector<int> findansSum(TreeNode* node)
	{
		if (node == NULL)
			return vector<int> {1, INT_MIN, INT_MAX, 0};

        vector<int> left = findansSum(node->left);
		vector<int> right = findansSum(node->right);

		bool isBST = (left[0] == 1 && right[0] == 1 && node->val > left[1] && node->val < right[2]);

		int sum = node->val + left[3] + right[3];

		if (isBST)
			ans = max(ans, sum);

		return vector<int> {isBST ? 1 : 0, max(node->val, right[1]), min(node->val, left[2]), sum};
	}
};
