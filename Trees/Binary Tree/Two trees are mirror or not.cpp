class Solution {
public:
	bool isMirrorTree(TreeNode *p, TreeNode *q)
	{
		if (p == NULL || q == NULL)
			return (p == q);
		return (p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left));
	}
};
