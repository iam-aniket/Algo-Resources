//Errichto - Legend
//https://www.youtube.com/watch?v=bm0q6huoriY
class Solution {
public:
	int ans = 0;
	int maxPathSum(TreeNode* root)
	{
		ans = dfs(root);
		return ans;
	}
	int dfs(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		
		int x = dfs(root->left);
		int y = dfs(root->right);

		ans = max(ans, x + y + root->val);

		return max(0, root->val + max(x, y));
	}
};
