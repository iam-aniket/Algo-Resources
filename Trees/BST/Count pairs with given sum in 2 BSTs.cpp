//GFG se liya hua h

class Solution
{
public:
	int countPair(TreeNode* root1, TreeNode* root2, int x)
	{
		if (root1 == NULL || root2 == NULL)
			return 0;

		stack<TreeNode*> s1, s2;
		TreeNode* top1, *top2;

		int count = 0;

		while (1)
		{

			while (root1 != NULL)
			{
				s1.push(root1);
				root1 = root1->left;
			}

			// to find next node in reverse
			// inorder traversal of BST 2
			while (root2 != NULL)
			{
				s2.push(root2);
				root2 = root2->right;
			}

			// if either gets empty then corresponding
			// tree traversal is completed
			if (s1.empty() || s2.empty())
				break;

			top1 = s1.top();
			top2 = s2.top();

			// if the sum of the node's is equal to 'x'
			if ((top1->data + top2->data) == x)
			{
				// increment count
				count++;

				// pop nodes from the respective stacks
				s1.pop();
				s2.pop();

				// insert next possible node in the
				// respective stacks
				root1 = top1->right;
				root2 = top2->left;
			}

			// move to next possible node in the
			// inoder traversal of BST 1
			else if ((top1->data + top2->data) < x)
			{
				s1.pop();
				root1 = top1->right;
			}

			// move to next possible node in the
			// reverse inoder traversal of BST 2
			else
			{
				s2.pop();
				root2 = top2->left;
			}
		}
		return count;
	}
};
