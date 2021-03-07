class Solution {
public:
	bool isSymmetric(TreeNode* root) 
	{
		if(root == NULL)
			return 1;
		
		bool x = symmetric(root->left,root->right);
		
		return x;
	}
	bool symmetric(TreeNode* l,TreeNode* r)
	{
		if(l == NULL || r == NULL)
			return l == r;

		if(l->val != r->val)
			return 0;
		
		return symmetric(l->left,r->right) && symmetric(l->right,r->left);
	}
};
