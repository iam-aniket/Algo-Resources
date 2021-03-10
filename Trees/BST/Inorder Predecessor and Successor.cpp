void findPreSuc(TreeNode* root, int val)
{
	if (root == NULL)  return ;

	if (root->val == val)
	{
		// the maximum value in left subtree is predecessor
		if (root->left != NULL)
		{
			TreeNode* tmp = root->left;
			while (tmp->right)
				tmp = tmp->right;
			pre = tmp ;
		}

		// the minimum value in right subtree is successor
		if (root->right != NULL)
		{
			TreeNode* tmp = root->right ;
			while (tmp->left)
				tmp = tmp->left ;
			suc = tmp ;
		}
		return ;
	}

	// If val is smaller than root's val, go to left subtree
	if (root->val > val)
	{
		suc = root ;
		findPreSuc(root->left, pre, suc, val) ;
	}
	else // go to right subtree
	{
		pre = root ;
		findPreSuc(root->right, pre, suc, val) ;
	}
}
