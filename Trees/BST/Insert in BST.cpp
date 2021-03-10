class Solution {
public:
	TreeNode* insertIntoBST(TreeNode *root, int val)
	{
		//return insertRecursive(root, val);
		return insertIterative(root, val);
	}
	// TC = O(n) but SC also O(n) stack space
	TreeNode* insertRecursive(TreeNode* root, int val)
	{
		if (root == NULL)
		{
			TreeNode *node = new TreeNode(val);
			return node;
		}

		if (val < root->val)
			root->left = insertIntoBST(root->left, val);
		else
			root->right = insertIntoBST(root->right, val);

		return root;
	}
	// TC O(n) & SC O(1)
	TreeNode* insertIterative(TreeNode* root, int val)
	{
		TreeNode* temp = root;
		if (root == NULL)
		{
			TreeNode* node = new TreeNode(val);
			return node;
		}
		//First find position to insert the node
		TreeNode* pos = NULL;
		while (temp != NULL)
		{
			pos = temp;//VVI - Since temp becomes NULL in next step hence storing is necessary
			if (temp->val < val)
				temp = temp->right;
			else
				temp = temp->left;
		}

		//Now just insert to pos left or right depending on val
		if (pos->val < val)
			pos->right = new TreeNode(val);
		else
			pos->left = new TreeNode(val);

		return root;
	}
};
