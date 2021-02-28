//Refer https://www.youtube.com/watch?v=AHRRIZWKGPY
//Kashish Mendidatta channel - BEST Explain

//This is an iterative approach called MORRIS Traversal
//It uses O(1) space but modifies the tree links but at last the modifications are restored also
TC = O(n)
SC = O(1)
//Logic is
// 1. Initialize current as root 
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
//       a) Find rightmost node in current left subtree OR
         
//          If we found right child == current
//              Go to the right, i.e. current = curent->right
//          Else
//              a) Make current as the right child of that rightmost 
//                 node we found; and 
//              b) Go to this left child, i.e., current = current->left

class Solution {
public:

	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		inorder(root, ans);
		return ans;
	}
	void inorder(TreeNode* root, vector<int>& ans)
	{
		TreeNode *cur;
		TreeNode *prev;
		cur = root;
		while (cur != NULL)
		{
			if (cur->left == NULL)
			{
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else
			{
				prev = cur->left;

				while (prev->right != NULL && prev->right != cur)
					prev = prev->right;

				if (prev->right == NULL)
				{
					prev->right = cur;
					cur = cur->left;
				}
				else
				{
					prev->right = NULL;
					ans.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
	}
};
