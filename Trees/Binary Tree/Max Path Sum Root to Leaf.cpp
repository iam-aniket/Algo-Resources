class Solution
{
public:
	int maxPathSum(TreeNode* root)
	{
		if (root == NULL)
			return 0;

		int curSum = 0, maxSum = 0;

		string temp, path;

		sum(root, curSum, maxSum, temp, path);

		cout << path << "\n";

		/*
		vector<int> temp, path;

		sum(root, curSum, maxSum, temp, path);

		for (auto x : path)
			cout << x << " ";
		*/

		return maxSum;
	}
	void sum(TreeNode* root, int curSum, int& maxSum, string temp, string& path)
	{
		temp += to_string(root->val) + " ";
		curSum += root->val;

		if (root->left == NULL && root->right == NULL && curSum > maxSum)
		{
			maxSum = max(curSum, maxSum);
			path = temp;
		}

		if (root->left != NULL)
			sum(root->left, curSum, maxSum, temp, path);
		if (root->right != NULL)
			sum(root->right, curSum, maxSum, temp, path);
	}
	void sum(TreeNode* root, int curSum, int& maxSum, vector<int> temp, vector<int>& path)
	{
		temp.push_back(root->val) ;
		curSum += root->val;

		if (root->left == NULL && root->right == NULL && curSum > maxSum)
		{
			maxSum = max(curSum, maxSum);
			path = temp;
		}

		if (root->left != NULL)
			sum(root->left, curSum, maxSum, temp, path);
		if (root->right != NULL)
			sum(root->right, curSum, maxSum, temp, path);
	}
};
