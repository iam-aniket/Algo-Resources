struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

vector<int> traverse(TreeNode* root)
{
	vector<int> ans;
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
//This can be applied to pre and post order too.
//No extra space other than stack of pair
void inorderIterative1(TreeNode* root, std::vector<int>& ans)
{
	stack<pair<TreeNode*, int>> s;

	s.push(make_pair(root, 0));

	while (!s.empty())
	{
		pair<TreeNode*, int> temp = s.top();
		TreeNode* cur = temp.first;
		int state = temp.second;

		s.pop();

		if (cur == NULL || state == 3) continue;

		s.push({cur, state + 1});

		if (state == 0)s.push({cur->left, 0});
		else if (state == 1)ans.push_back(cur->val);
		else if (state == 2)s.push({cur->right, 0});
	}
}
//This can be applied to pre and post order too.
//Uses map + stack as extra space
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
		else if (cnt[cur] == 1)ans.push_back(cur->val);
		else if (cnt[cur] == 2)s.push(cur->right);
		else
			s.pop();

		cnt[cur]++;
	}
}
//Only PRE + INORDER but NOT Post order - simple stack
void inorderIterativeButNotPostOrder(TreeNode* root, vector<int>& ans)
{
	if (root == NULL)
		return;

	stack<TreeNode*> s;

	while (root != NULL || !s.empty())
	{
		while (root != NULL)
		{
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		ans.push_back(root->val);
		root = root->right;
	}
}
//O(1) SC by changing tree links and then again changing to original
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
