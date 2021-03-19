//Not sure this solution - from Adhitya Verma DP
int unboundedKnapsackMinCoinChange(int weight[], int w, int n)
{
	int dp[n + 1][w + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 0;

	for (int i = 0; i < w + 1; i++)
		dp[0][i] = INT_MAX - 1;

	for (int i = 1; i < w + 1; i++)
	{
		if (i % weight[0] == 0)
			dp[1][i] = j / weight[0];
		else
			dp[1][i] = INT_MAX - 1;
	}
	for (int i = 1; i < n + 1; i++) //Note : i Started from 1
	{
		for (int j = 1; j < w + 1; j++)
		{
			if (weight[i - 1] <= j)
				dp[i][j] = min(dp[i][j - weight[i - 1]] , dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][w];
}
//1D Array DP method - correct
int change(int coins[], int n, int amount)
{
	int dp[amount + 1];

	for (int i = 0; i < amount + 1; i++)
		dp[i] = INT_MAX - 1;

	dp[0] = 0;

	for (int i = 1; i < amount + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= coins[j])
				dp[i] = min(1 + dp[i - coins[j]], dp[i]) ;
		}
	}
	if (dp[amount] == INT_MAX - 1)
		return -1;
	return dp[amount];
}
