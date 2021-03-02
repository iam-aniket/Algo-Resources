/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		vector<vector<int>> ans;
		zigzagBFS(root, ans);
		return ans;
	}
	void zigzagBFS(TreeNode* root, vector<vector<int>>& ans)
	{
		if (root == NULL)return;

		queue<TreeNode*> q;
		q.push(root);

		bool flag = 0;
		int ct = 0;

		while (!q.empty())
		{
			int n = q.size();
			vector<int> level(n, 0);

			if (ct % 2 == 0)
				for (int i = 0; i < n; i++)
				{
					TreeNode* temp = q.front();
					q.pop();
					level[i] = temp->val;
					//level.push_back(temp->val);
					if (temp->left != NULL)q.push(temp->left);
					if (temp->right != NULL)q.push(temp->right);
				}

			else
				for (int i = 0; i < n; i++)
				{
					TreeNode* temp = q.front();
					q.pop();
					level[n - i - 1] = temp->val;
					//level.push_back(temp->val);
					if (temp->left != NULL)q.push(temp->left);
					if (temp->right != NULL)q.push(temp->right);
				}

			// if (flag)
			// reverse(level.begin(), level.end());

			ans.push_back(level);

			ct++;

			//flag = !flag;
		}
	}
};
