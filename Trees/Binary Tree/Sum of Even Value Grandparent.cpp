//Storing parents in map approach and then accessing GP value from map
//Accepted but not space + time efficient
class Solution {
public:
	int ans = 0;
	int sumEvenGrandparent(TreeNode* root)
	{
		map<TreeNode*, TreeNode*> m;
		parent(root, root, m, 0);
		//for (auto x : m)
		//	cout << x.first->val << "->" << x.second->val << "\n";
		return ans;
	}
	void parent(TreeNode* root, TreeNode* par, map<TreeNode*, TreeNode*>& m, int depth)
	{
		if (root == NULL)
			return;

		if (depth >= 1)
			m[root] = par;

		if (depth >= 2)
			if (m[m[root]]->val % 2 == 0)
				ans += root->val;

		parent(root->left, root, m, depth + 1);
		parent(root->right, root, m, depth + 1);
	}
};
