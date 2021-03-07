//Just recurse for current, parent, and Grandparent
//No need to store 
//Hence Efficient TC & O(1) SC
class Solution {
public:
	int ans = 0;
	int sumEvenGrandparent(TreeNode* root)
	{
		solve(root, NULL, NULL);
		return ans;
	}
	void solve(TreeNode* root, TreeNode* parent, TreeNode* grandparent)
	{
		if (root == NULL)
			return;

		if (grandparent != NULL && grandparent->val % 2 == 0)
			ans += root->val;

		solve(root->left, root, parent);
		solve(root->right, root, parent);
	}
};
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
