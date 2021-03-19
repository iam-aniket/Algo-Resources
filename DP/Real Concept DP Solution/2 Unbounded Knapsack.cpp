int unboundedKnapsack(int weight[], int val[], int w, int n)
{
	int dp[n + 1][w + 1];
	
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i < n + 1; i++) //Note : i Started from 1
	{
		for (int j = 1; j < w + 1; j++)
		{
			//We can take each element any no of times
			//So If chosed - do again for dp[i][...];
			//But if not chosen - go next ele dp[i-1][j];
			if (weight[i - 1] <= j)
				dp[i][j] = max(val[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][w];
}
