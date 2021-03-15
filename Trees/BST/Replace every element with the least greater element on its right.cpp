class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums)
	{
		TreeNode* root = NULL;

		replace(nums);

		return root;
	}
	void replace(vector<int>& arr)
	{
		int n = arr.size();
		TreeNode* root = NULL;

		// start from right to left
		for (int i = n - 1; i >= 0; i--)
		{
			TreeNode* next = NULL;

			// insert current element into BST and
			// find its inorder successor
			insert(root, arr[i], next);

			// replace element by its inorder
			// successor in BST
			if (next != NULL)
				arr[i] = next->val;
			else    // No inorder successor
				arr[i] = -1;
		}

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	void insert(TreeNode*& node, int val, TreeNode*& next)
	{
		if (node == NULL)
			node = new TreeNode(val);

		if (val < node->val)
		{
			next = node;
			insert(node->left, val, next);
		}
		else if (val > node->val)
			insert(node->right, val, next);
	}
};
