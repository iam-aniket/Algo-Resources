//https://leetcode.com/problems/all-elements-in-two-binary-search-trees

//Knowledge Center YT 
//https://www.youtube.com/watch?v=B97Hk1H2x2s
class Solution
{
public:
	vector<int> ans1, ans2;

	vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
	{
		vector<int> ans;

		inorder(root1, ans1);
		inorder(root2, ans2);

		int i = 0, j = 0, n1 = ans1.size(), n2 = ans2.size();

		while (i < n1 && j < n2)
		{
			if (ans1[i] < ans2[j])
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
		//Left out elements if any
		while (i < n1)
		{
			ans.push_back(ans1[i]);
			i++;
		}
		//Left out elements if any
		while (j < n2)
		{
			ans.push_back(ans2[j]);
			j++;
		}

		return ans;
	}
	void inorder(TreeNode* root, vector<int>& ans)
	{
		if (root == NULL)
			return;

		inorder(root->left, ans);
		ans.push_back(root->val);
		inorder(root->right, ans);
	}
};
