//DFS Solution
int maxDepth(TreeNode *root)
{
	return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
//BFS Solution
