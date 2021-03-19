int LCSTopDown(string x, string y, int m, int n)
{
	int dp[m + 1][n + 1];
	//Base condition changed to initialization
	for (int i = 0; i < m + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
	int ans = 0;
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			//Note: i-1 & j-1 compared
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	return ans;
}
