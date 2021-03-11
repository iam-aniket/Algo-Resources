class Solution {
public:
	int prev = 0;
	TreeNode* bstToGst(TreeNode* root)
	{
		inorderRev(root);
		return root;
	}
	void inorderRev(TreeNode* root)
	{
		if (root == NULL) return;

		inorderRev(root->right);
		root->val += prev;
		prev = root->val;
		inorderRev(root->left);
	}
};
