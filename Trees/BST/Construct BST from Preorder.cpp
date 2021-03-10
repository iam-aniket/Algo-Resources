class Solution {
public:
	int idx = 0;
	TreeNode* bstFromPreorder(vector<int>& preorder)
	{
		return helper(preorder, INT_MAX);
	}

	TreeNode* helper(vector<int> preorder, int limit)
	{
		if (idx == preorder.size() || preorder[idx] > limit)
			return NULL;

		TreeNode* root = new TreeNode(preorder[idx]);
		idx++;//VVI - since idx is changed only for left and not right

		//For left part parent is the limit
		root->left = helper(preorder, root->val);
		//But for right part Ancestr value is limit
		root->right = helper(preorder, limit);

		return root;
	}
};
