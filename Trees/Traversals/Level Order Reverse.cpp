class Solution {
public:

	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> ans;
		levelOrderBottomBFS(root, ans, 0);
		//reverse(ans.begin(),ans.end());	//only for DFS
		return ans;
	}
	void levelOrderBottomBFS(TreeNode* root, vector<vector<int>>& ans)
	{
		if (root == NULL)return;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			vector<int> level;
			for (int i = 0; i < n; i++)
			{
				TreeNode* temp = q.front();
				q.pop();
				level.push_back(temp->val);
				if (temp->left != NULL)q.push(temp->left);
				if (temp->right != NULL)q.push(temp->right);
			}
			ans.push_back(level);
		}
		reverse(ans.begin(), ans.end());
	}
	void levelOrderBottomDFS(TreeNode* root, vector<vector<int>>& ans, int depth)
	{
		if (root == NULL)return;

		if (ans.size() == depth)
			ans.push_back(vector<int>());

		ans[depth].push_back(root->val);

		levelOrderBottomDFS(root->left, ans, depth + 1);
		levelOrderBottomDFS(root->right, ans, depth + 1);
	}
	//This uses stack - Kashish - but not 2d vector return only 1d vect return
	void levelOrderReverse(TreeNode* root, std::vector<int>& ans)
	{
		if (root == NULL)return;

		queue<TreeNode*> q;
		stack<int> s;

		q.push(root);

		while (!q.empty())
		{
			TreeNode* temp = q.front();
			s.push(temp->val);
			q.pop();

			if (temp->left != NULL)
				q.push(temp->left);

			if (temp->right != NULL)
				q.push(temp->right);
		}

		while (!s.empty())
		{
			int temp = s.top();
			s.pop();
			ans.push_back(temp);
		}
	}
};
