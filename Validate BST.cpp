class Solution {
public:
	bool isValidBST(TreeNode* root)
	{
		if (root == NULL)
			return true;

		stack<TreeNode*> s;
		TreeNode* pre = NULL;

		while (root != NULL || !s.empty())
		{
			while (root != NULL)
			{
				s.push(root);
				root = root->left;
			}
			TreeNode * temp = s.top();
			root = temp;
			s.pop();
			if (pre != NULL && root->val <= pre->val)
				return false;
			pre = root;
			root = root->right;
		}
		return true;
	}
};
