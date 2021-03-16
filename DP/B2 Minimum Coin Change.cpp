class Solution {
public:
	int change(int amount, vector<int>& coins)
	{
		int dp[amount + 1];
        for(int i = 0; i < amount+1; i++)
            dp[i] = 0;
		dp[0] = 1;
		for (int coin : coins)
		{
			for (int i = coin; i <= amount; i++)
			{
				dp[i] += dp[i - coin];
			}
		}
		return dp[amount];
	}
};
