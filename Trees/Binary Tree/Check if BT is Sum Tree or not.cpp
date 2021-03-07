//https://www.techiedelight.com/check-given-binary-tree-sum-tree-not/
int isSumTree(Node* root)
{
	// base case: empty tree
	if (root == nullptr) {
		return 0;
	}

	// special case: leaf node
	if (root->left == nullptr && root->right == nullptr)
	{
		return root->key;
	}

	// if the root's value is equal to the sum of all elements present in its
	// left and right subtree
	if (root->key == isSumTree(root->left) + isSumTree(root->right)) {
		return 2 * root->key;
	}

	return INT_MIN;
}
int main()
{
	if (isSumTree(root) != INT_MIN)
	{
		cout << "Binary tree is a sum tree";
	}
	else
	{
		cout << "Binary tree is not a sum tree";
	}
}
