class Solution {
public:
	bool isMirrorTree(TreeNode *p, TreeNode *q)
	{
		if (p == NULL || q == NULL)
			return (p == q);
		return (p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left));
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Another Solution///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Find inorder traversal of both trees
//If one of the traversal is reverse of other then they are mirror trees
//Else not
