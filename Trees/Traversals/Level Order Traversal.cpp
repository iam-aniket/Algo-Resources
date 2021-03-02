//https://www.youtube.com/watch?v=N-WwZG14vbg
//Kashish video also
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ans;
		levelOrderBFS(root, ans);
		return ans;
	}
	void levelOrderBFS(TreeNode* root, vector<vector<int>>& ans)
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
	}
	void levelOrderDFS(TreeNode* root, vector<vector<int>>& ans, int depth)
	{
		if (root == NULL)return;

		if (ans.size() == depth)
			ans.push_back(vector<int>());

		ans[depth].push_back(root->val);

		levelOrderDFS(root->left, ans, depth + 1);
		levelOrderDFS(root->right, ans, depth + 1);
	}
};
