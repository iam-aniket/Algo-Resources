//n is size of weight array
//w denotes change amount required
int unboundedKnapsackCoinChange(int weight[], int w, int n)
{
	int dp[n + 1][w + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < w + 1; j++)
		{
			if (i == 0)
				dp[i][j] = 0;
			if (j == 0)
				dp[i][j] = 1;
		}
	for (int i = 1; i < n + 1; i++) //Note : i Started from 1
	{
		for (int j = 1; j < w + 1; j++)
		{
			if (weight[i - 1] <= j)
				dp[i][j] = dp[i][j - weight[i - 1]] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][w];
}
long long int ArrayCoinChange(int weight[], int w, int n)
{
	long long int dp[w + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < w + 1; j++)
		{
			if (j >= weight[i])
				dp[j] += dp[j - weight[i]];
		}
	}
	return dp[w];
}
