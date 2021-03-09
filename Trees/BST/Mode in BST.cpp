//https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/98191/C%2B%2B-O(n)-time-and-O(1)-space-by-inorder-traversal

//But Refer this also
//https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/98101/Proper-O(1)-space

class Solution {
public:
	int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
	vector<int> res;

	vector<int> findMode(TreeNode *root)
	{
		inorderTraversal(root);
		return res;
	}

	void inorderTraversal(TreeNode *root)
	{
		if (root == NULL) return; // Stop condition
		inorderTraversal(root->left); // Traverse left subtree
		if (precursor == root->val) currFreq++;
		else currFreq = 1;
		if (currFreq > maxFreq)
		{	// Current node value has higher frequency than any previous visited
			res.clear();
			maxFreq = currFreq;
			res.push_back(root->val);
		}
		else if (currFreq == maxFreq)
		{	// Current node value has a frequency equal to the highest of previous visited
			res.push_back(root->val);
		}
		precursor = root->val; // Update the precursor
		inorderTraversal(root->right); // Traverse right subtree
	}
};
