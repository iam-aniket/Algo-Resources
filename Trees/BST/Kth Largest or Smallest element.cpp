//Kth Smallest - Inorder
class Solution
{
public:
	vector<int> ans;
	int x = 0;
	int kthSmallest(TreeNode* root, int k)
	{
		inorder(root, k);
		return x;
	}
	void inorder(TreeNode* root, int k)
	{
		if (root == NULL)
			return;

		TreeNode* temp = NULL;

		stack<TreeNode*> s;

		while (root != NULL || !s.empty())
		{
			while (root != NULL)
			{
				s.push(root);
				root = root->left;
			}

			TreeNode* temp = s.top();
			root = temp;

			s.pop();

			if (--k == 0)
				break;

			ans.push_back(temp->val);

			root = root->right;
		}
		x = root->val;
	}
};

//For Kth Largest - Use Reverse inorder ie; right , node , then left.
