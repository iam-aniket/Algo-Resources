int dp[1001][1001];

int lcsCalculate(string s1, string s2, int m, int n)
{
	memset(dp, -1, sizeof(dp));
	int q = LCSTopDown(s1, s2, m, n);
	return q;
}
//Recursive Solution
int LCS(string x, string y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	//Note: m-1 & n-1 compared
	if (x[m - 1] == y[n - 1])
		return 1 + LCS(x, y, m - 1, n - 1);
	else
		return max(LCS(x, y, m, n - 1), LCS(x, y, m - 1, n));
}
//Memoized Solution
int LCSMemoized(string x, string y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	if (dp[m][n] != -1)
		return dp[m][n];

	//Note: m-1 & n-1 compared
	if (x[m - 1] == y[n - 1])
	{
		dp[m][n] = 1 + LCSMemoized(x, y, m - 1, n - 1);
		return dp[m][n];
	}
	else
	{
		dp[m][n] = max(LCSMemoized(x, y, m, n - 1), LCSMemoized(x, y, m - 1, n));
		return dp[m][n];
	}
}
//Top-Down DP
int LCSTopDown(string x, string y, int m, int n)
{
	int dp[m + 1][n + 1];
	//Base condition changed to initialization
	for (int i = 0; i < m + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			//Note: i-1 & j-1 compared
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m][n];
}
