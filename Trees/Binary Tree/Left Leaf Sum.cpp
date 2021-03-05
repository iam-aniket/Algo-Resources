class Solution {
public:
    int sum = 0;
		
	int sumOfLeftLeaves(TreeNode* root)
	{
		bool x = 0;
        if(root == NULL)
            return 0;
		if (root->left == NULL && root->right == NULL)
			return 0;
		sumLeft(root, x);
        return sum;
	}
	void sumLeft(TreeNode* root, bool flag)
	{
		if (root == NULL)
			return;
		if (flag && root->left == NULL && root->right == NULL)
			sum += root->val;
		sumLeft(root->left, 1);
		sumLeft(root->right, 0);
	}
};
