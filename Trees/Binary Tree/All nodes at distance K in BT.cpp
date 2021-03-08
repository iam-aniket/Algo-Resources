//Kashish
//BackToBack SWE
class Solution
{
public:

	unordered_set<TreeNode*> visited;
	unordered_map<TreeNode*, TreeNode*> m;
	vector<int> ans;

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
	{
		parent(root, NULL, 0, m);
		
        solveDFS(target, K);
		//solveBFS(root, target, K);

		return ans;
	}
	//Building Parent of every node
	void parent(TreeNode* root, TreeNode* par, int depth, unordered_map<TreeNode*, TreeNode*>& m)
	{
		if (root == NULL)
			return;

		if (depth >= 1)
			m[root] = par;

		parent(root->left, root, depth + 1, m);
		parent(root->right, root, depth + 1, m);
	}
	//DFS Approach - Start from target node and go depth wise
	void solveDFS(TreeNode* node, int k)
	{
		if (node == NULL)
			return;

		if (visited.find(node) != visited.end())
			return;

		visited.insert(node);

		if (k == 0)
		{
			ans.push_back(node->val);
			return;
		}

		solveDFS(node->left, k - 1);
		solveDFS(node->right, k - 1);
		solveDFS(m[node], k - 1);
	}
	//BFS Approach - Start from target node and go breadth wise using queue
	void solveBFS(TreeNode* root, TreeNode* target, int k)
	{
		queue<TreeNode*> q;
		q.push(target);

		visited.insert(target);
		int curr_level = 0;

		while (!q.empty())
		{
			/*BFS to go upto K level from target node and using our hashtable info*/
			int size = q.size();

			if (curr_level++ == k) break;

			for (int i = 0; i < size; i++)
			{
				TreeNode* current = q.front();
				q.pop();

				if (current->left && visited.find(current->left) == visited.end())
				{
					q.push(current->left);
					visited.insert(current->left);
				}
				if (current->right && visited.find(current->right) == visited.end())
				{
					q.push(current->right);
					visited.insert(current->right);
				}
				if (m[current] && visited.find(m[current]) == visited.end())
				{
					q.push(m[current]);
					visited.insert(m[current]);
				}
			}
		}
		while (!q.empty())
		{
			TreeNode* current = q.front();
			q.pop();
			ans.push_back(current->val);
		}
	}
};
