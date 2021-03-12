//https://leetcode.com/problems/all-elements-in-two-binary-search-trees
class Solution {
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
	{
		vector<int> ans;

		//Two stacks created for inorder type compare of both trees
		stack<TreeNode*> s1, s2;

		//While any stack is not empty or node still left to explore from tree
		while (!s1.empty() || root1 != NULL || !s2.empty() || root2 != NULL)
		{
			//Push full left nodes of tree1
			while (root1 != NULL)
			{
				s1.push(root1);
				root1 = root1->left;
			}
			//Push full left nodes of tree2
			while (root2 != NULL)
			{
				s2.push(root2);
				root2 = root2->left;
			}

			//Compare both stacks top
			if (!s1.empty() && !s2.empty())
			{
				if (s1.top()->val < s2.top()->val)
				{
					TreeNode* temp = s1.top();
					s1.pop();
					ans.push_back(temp->val);
					root1 = temp->right;
				}
				else
				{
					TreeNode* temp = s2.top();
					s2.pop();
					ans.push_back(temp->val);
					root2 = temp->right;
				}
			}
			else if (!s1.empty())
			{
				TreeNode* temp = s1.top();
				s1.pop();
				ans.push_back(temp->val);
				root1 = temp->right;
			}
			else if (!s2.empty())
			{
				TreeNode* temp = s2.top();
				s2.pop();
				ans.push_back(temp->val);
				root2 = temp->right;
			}
		}
		return ans;
	}
};
