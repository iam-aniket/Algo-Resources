class Solution {
public:
	TreeNode* binaryTreeToBST(TreeNode* root)
	{
		vector<int> ans;
		inorderTraverse(root, ans);
		return solve(ans, 0, ans.size() - 1);
	}
	void inorderTraverse(TreeNode* root, vector<int>& ans)
	{
		if (root == NULL) return;

		inorderTraverse(root->left);
		ans.push_back(root->val);
		inorderTraverse(root->right);
	}
	TreeNode* solve(vector<int> ans, int start, int end)
	{
		if (end <= start)
			return NULL;

		int midIdx = (end + start) / 2;

		//Create node for middle element
		TreeNode* root = new TreeNode(ans[midIdx]);

		//Push left and right vector part, to root's ptr
		root->left = solve(nums, start, midIdx);
		root->right = solve(nums, midIdx + 1, end);

		return root;
	}
};
