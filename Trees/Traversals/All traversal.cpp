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
	inorder(root, ans);
	return ans;
}

void inorder(TreeNode* root, std::vector<int>& ans)
{
	if (root == NULL)return;

	inorder(root->left, ans);
	ans.pb(root->val);
	inorder(root->right, ans);
}

void preorder(TreeNode* root, std::vector<int>& ans)
{
	if (root == NULL)return;

	ans.pb(root->val);
	preorder(root->left, ans);
	preorder(root->right, ans);
}

void postorder(TreeNode* root, std::vector<int>& ans)
{
	if (root == NULL)return;

	postorder(root->left, ans);
	postorder(root->right, ans);
	ans.pb(root->val);
}

void inorderIterative(TreeNode* root, std::vector<int>& ans)
{
	stack<TreeNode*> s;
	unordered_map<TreeNode*, int> cnt;

	s.push(root);

	while (!s.empty())
	{
		TreeNode* cur = s.top();

		if (cur == NULL)
		{
			s.pop();
			continue;
		}

		if (cnt[cur] == 0)s.push(cur->left);
		else if (cnt[cur] == 1)ans.pb(cur->val);
		else if (cnt[cur] == 2)s.push(cur->right);
		else
			s.pop();

		cnt[cur]++;
	}
}

void inorderMorris(TreeNode* root, std::vector<int>& ans)
{
	TreeNode* cur;
	TreeNode* prev;
	cur = root;

	while (cur != NULL)
	{
		if (cur->left == NULL)
		{
			ans.pb(cur->val);
			cur = cur->right;
		}
		else
		{
			prev = cur->left;

			while (prev->right != NULL && prev->right != cur)
				prev = prev->right;

			if (prev->right == NULL)
			{
				prev->right = cur;
				cur = cur->left;
			}

			else
			{
				prev->right = NULL;
				ans.pb(cur->val);
				cur = cur->right;
			}
		}
	}
}
