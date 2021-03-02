//DFS Solution
int maxDepth1(TreeNode *root)
{
	return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
//BFS Solution
int maxDepth(TreeNode *root)
{
	if (root == NULL)
		return 0;

	int ct = 0;
	queue<TreeNode *> q;
	q.push(root);

	while (!q.empty())
	{
		++ ct;
		for (int i = 0, n = q.size(); i < n; ++ i)
		{
			TreeNode *p = q.front();
			q.pop();

			if (p -> left != NULL)
				q.push(p -> left);
			if (p -> right != NULL)
				q.push(p -> right);
		}
	}
	return ct;
}
