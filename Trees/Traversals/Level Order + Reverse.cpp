struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

vector<int> traverse(TreeNode* root)
{
	std::vector<int> ans;
	levelOrder(root, ans);
	for (auto x : ans)
		cout << x << " ";
	return ans;
}

void levelOrder(TreeNode* root, std::vector<int>& ans)
{
	if (root == NULL)return;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* temp = q.front();
		ans.pb(temp->val);
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
}

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
