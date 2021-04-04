class Solution {
public:
	int rob(vector<int>& nums)
	{
		if (nums.size() == 1)return nums[0];

		if (nums.size() == 2)return max(nums[0], nums[1]);

		//Including First House till house n-1;
		int x = robOriginal(nums, 0, nums.size() - 1);

		//Excluding First House till house n;
		int y = robOriginal(nums, 1, nums.size());

		return max(x, y);
	}
	int robOriginal(vector<int>& nums, int start, int end)
	{

		int dp[nums.size() + 1];
		memset(dp, 0, sizeof(dp));

		//Same as House Robber 1
		if (start == 0)
		{
			dp[0] = nums[0];
			dp[1] = max(nums[0], nums[1]);
		}
		//We start from House 1 till last house
		else
			dp[1] = nums[1];

		for (int i = 2; i < end; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

		return dp[end - 1];
	}
};
