class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return sortedArrayToBST(nums, 0, nums.size());
	}
	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end)
	{
		if (end <= start)
			return NULL;

		int midIdx = (end + start) / 2;

		//Create node for middle element
		TreeNode* root = new TreeNode(nums[midIdx]);

		//Push left and right vector part, to root's ptr
		root->left = sortedArrayToBST(nums, start, midIdx);
		root->right = sortedArrayToBST(nums, midIdx + 1, end);

		return root;
	}
};
