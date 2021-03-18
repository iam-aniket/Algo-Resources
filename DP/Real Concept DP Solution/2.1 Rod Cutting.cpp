int unboundedKnapsackRodCutting(int val[], int n)
{
	int w = n;
	int weight[n + 1];
	for (int i = 0; i < n + 1; i++)
		weight[i] = i + 1;
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
//O(n^2)TC But O(n)SC
//Min cost till i th length of rod
int ArrayMethodRodCutting(int val[], int n)
{
	int dp[n + 1];
	dp[0] = 0;
	int i, j;

	// Build the table val[] in bottom up manner and return the last entry
	// from the table
	for (i = 1; i <= n; i++)
	{
		int max_val = INT_MIN;
		for (j = 0; j < i; j++)
			max_val = max(max_val, price[j] + dp[i - j - 1]);
		dp[i] = max_val;
	}

	return dp[n];
}
