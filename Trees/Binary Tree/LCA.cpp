Refer this solution also
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65369/Short-and-clean-C%2B%2B-solution

//My approach
//Good TC O(n) but SC is bad since map + set also used.
//So ref other solutions

class Solution {
public:
	unordered_map<TreeNode*, TreeNode*> m;

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		unordered_set<TreeNode*> s;
		TreeNode* node = root;

		parent(root, NULL, 0, m);

		s.insert(p);
		s.insert(q);

		while ((p != root || q != root))
		{
			if (s.find(m[p]) != s.end())
			{
				node = m[p];
				break;
			}
			else
			{
				if (m[p] != NULL)
				{
					s.insert(m[p]);
					p = m[p];
				}
			}

			if (s.find(m[q]) != s.end())
			{
				node = m[q];
				break;
			}
			else
			{
				if (m[q] != NULL)
				{
					s.insert(m[q]);
					q = m[q];
				}
			}
		}
		return node;
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
};
