//https://github.com/iam-aniket/Algo-Resources/blob/main/Trees/BST/BST1.png
//https://github.com/iam-aniket/Algo-Resources/blob/main/Trees/BST/BST2.png

class Solution {
public:
	void flatten(TreeNode* root)
	{
		flatten3(root);//Best
	}

	//Simple Easy but unnecessary Long Solution
	//Need a lot of traversal in the "while" loop
	void flatten1(TreeNode* root)
	{
		if (!root) return;

		flatten1(root->left);
		flatten1(root->right);

		TreeNode *temp = root->right;
		root->right = root->left;
		root->left = NULL;

		while (root->right)
			root = root->right;

		root->right = temp;
	}
	/*
	The idea is very simple(3 steps) :

	1) Flatten left subtree

	2) Flatten right subtree

	3) concatenate root -> left flatten subtree -> right flatten subtree
	*/

	//But this Solution is greater than O(n)
	//because of step 2, for each recursive call of flatten()
	//you need to traverse the flatten left subtree to the end.

	void flatten2(TreeNode* root)
	{
		if (root == NULL)
			return;

		flatten(root->left);
		flatten(root->right);

		// save current right for concatination
		TreeNode* right = root->right;

		if (root->left != NULL)
		{

			// step 1: concatinate root with left flatten subtree
			root->right = root->left;
			root->left = NULL; // set left to NULL

			// step 2: move to the end of new added flatten subtree
			while (root->right != NULL)
				root = root->right;

			// step 3: contatinate left flatten subtree with flatten right subtree
			root->right = right;
		}
	}

	//To improve the performance of the algorithm

	//---------->   Refer BST1,BST2.png image for intution behind this   <-------------//

	//Best O(n)TC O(1)SC

	//https://github.com/iam-aniket/Algo-Resources/blob/main/Trees/BST/BST1.png
	//https://github.com/iam-aniket/Algo-Resources/blob/main/Trees/BST/BST2.png

	void flatten3(TreeNode *root)
	{
		TreeNode*now = root;
		while (now)
		{
			if (now->left)
			{
				//Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while (pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
				//Use current node's left subtree to replace its right subtree(original right
				//subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
	}
};
