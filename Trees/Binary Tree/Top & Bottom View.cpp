//Watch Tech Dose to refer
//https://www.youtube.com/watch?v=kqHNP6NTzME

//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/C%2B%2B-BFSDFS

class Solution
{
public:
	//Create Vertical View then just first element from each line is top view
	//And last element is bottom view
	vector<int> verticalTraversal(TreeNode* root)
	{
		map<int, map<int, multiset<int>>> nodes;
		queue<pair<TreeNode*, pair<int, int>>> todo;
		todo.push({root, {0, 0}});

		while (!todo.empty())
		{
			auto p = todo.front();
			todo.pop();

			TreeNode* node = p.first;
			int x = p.second.first, y = p.second.second;

			nodes[x][y].insert(node -> val);

			if (node -> left)
				todo.push({node -> left, {x - 1, y + 1}});

			if (node -> right)
				todo.push({node -> right, {x + 1, y + 1}});
		}
		vector<vector<int>> ans;

		for (auto p : nodes)
		{
			vector<int> col;
			for (auto q : p.second)
			{
				col.insert(col.end(), q.second.begin(), q.second.end());
			}
			ans.push_back(col);
		}

		vector<int> top;

		//First element from every vertical line is top view
		for (auto x : ans)
			top.push_back(x[0]);

		return top;
//////////////////////////////////Bottom View/////////////////////////////
		/*
		vector<int> bottom;

		//Last element from every vertical line is bottom view
		for (auto x : ans)
			bottom.push_back(x[x.size() - 1]);

		return bottom;
		*/
	}
};
