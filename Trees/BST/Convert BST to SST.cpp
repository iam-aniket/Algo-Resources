//Small sum tree
class Solution {
public:
	int prev = 0;
	TreeNode* bstToSst(TreeNode* root)
	{
		inorder(root);
		return root;
	}
	void inorder(TreeNode* root)
	{
		if (root == NULL) return;

		inorder(root->left);
		root->val += prev;
		prev = root->val;
		inorder(root->right);
	}
};
