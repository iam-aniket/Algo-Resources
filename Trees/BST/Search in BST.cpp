class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val)
	{
		TreeNode* ans = searchBSTIterative(root, val);
		return ans;
	}
	TreeNode* searchBSTRecursive(TreeNode* root, int val)
	{
		if (root == NULL)
			return root;

		if (root->val == val)
			return root;

		else if (root->val < val)
			return searchBST(root->right, val);

		else
			return searchBST(root->left, val);
	}
	TreeNode* searchBSTIterative(TreeNode* root, int val)
	{
		if (root == NULL)
			return NULL;
		while (root != NULL && root->val != val)
		{
			if (root->val < val)
				root = root->right;
			else
				root = root->left;
		}
		return root;
	}
};
