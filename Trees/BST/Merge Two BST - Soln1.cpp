class Solution 
{
public:
	vector<int> ans1, ans2;
	
	vector<int> mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		vector<int> ans;

		inorder(root1, ans1);
		inorder(root2, ans2);

		int i = 0, j = 0, n1 = ans1.size(), n2 = ans2.size();

		while (i < n1 - 1 && j < n2 - 1)
		{
			if (ans1[i] < ans1[j])
			{
				ans.push_back(ans1[i]);
				i++;
			}
			else
			{
				ans.push_back(ans2[j]);
				j++;
			}
		}
		while (i < n1)
		{
			ans.push_back(ans1[i]);
			i++;
		}
		while (j < n2)
		{
			ans.push_back(ans2[j]);
			j++;
		}

		for (auto x : ans)
			cout << x << " ";

		return ans;
	}
	void inorder(TreeNode* root, vector<int>& ans)
	{
		if (root == NULL)
			return;

		inorder(root->left, ansx);
		ansx.push_back(root->val);
		inorder(root->right, ansx);
	}
};
