class Solution {
public:
	unordered_set<int> s, leaf;
	bool isValidBST(TreeNode* root)
	{
		//Handle case for only positive nos
		s.insert(0);

		int flag = 0;

		inorder(root);

		for (auto i : leaf)
		{
			if (s.find(i + 1) != s.end() && s.find(i - 1) != s.end())
			{
				flag = i;
				break;
			}
		}

		if (flag)
			cout << "Tree has Dead End at " << flag << " !\n";
		else
			cout << "No Dead End\n";

		return 1;
	}
	void inorder(TreeNode* root)
	{
		if (root == NULL)
			return;
		//Insert leaf in another set so no need to traverse again!
		if (root->left == NULL && root->right == NULL)
			leaf.insert(root->val);

		inorder(root->left);
		s.insert(root->val);
		inorder(root->right);
	}
};
