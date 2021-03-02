//The question can be solved by small modification to program of Height of tree.

//The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node ) is the diameter. 
//Keep track of maxium diameter duing traversal and find the height of the tree.

//d=max(d,ld+rd); => This line maintains the max diameter.
	
int diameterOfBinaryTree(TreeNode* root)
{
	int d = 0;
	dfs(root, d);
	return d;
}
int dfs(TreeNode* root, int &d)
{
	if (root == NULL) return 0;

	//left max depth
	int ld = dfs(root->left, d);

	//right max depth
	int rd = dfs(root->right, d);

	//d = max value of ld + rd
	d = max(d, ld + rd);

	return max(ld, rd) + 1;
}
