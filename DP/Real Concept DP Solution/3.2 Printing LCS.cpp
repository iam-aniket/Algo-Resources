class Solution {
public:
	int longestCommonSubsequence(string x, string y)
	{
		int m = x.size(), n = y.size();
		int dp[m + 1][n + 1];
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < m + 1; i++)
			for (int j = 0; j < n + 1; j++)
				if (i == 0 || j == 0)
					dp[i][j] = 0;
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (x[i - 1] == y[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		//Printing LCS - Backtrack from matrix
		vector<char> ans;
		int i = m, j = n;
		while (i > 0 && j != 0)
		{
			if (x[i - 1] == y[j - 1])
			{
				ans.push_back(x[i - 1]);
				i--;
				j--;
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
					i--;
				else
					j--;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
		return dp[m][n];
	}
};
