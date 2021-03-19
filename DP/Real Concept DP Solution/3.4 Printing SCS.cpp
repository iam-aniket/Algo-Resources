class Solution {
public:
	string shortestCommonSupersequence1(string x, string y)
	{
		int m = x.size(), n = y.size();
		int dp[m + 1][n + 1];
		memset(dp, -1, sizeof(dp));
		string ans;
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
		int lcsLength = dp[m][n];

		int scsLength = m + n - lcsLength;

		//Printing SCS - Backtrack from matrix
		//Change is add to ans even when chosing non same value
		int index = scsLength - 1;

		int i = m, j = n;
		while (i > 0 && j > 0)
		{
			if (x[i - 1] == y[j - 1])
			{
				ans.push_back(x[i - 1]);
				i--;
				j--;
				index--;
			}
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					ans.push_back(x[i - 1]);
					i--;
					index--;
				}
				else
				{
					ans.push_back(y[j - 1]);
					j--;
					index--;
				}
			}
		}
		while (i > 0)
		{
			ans.push_back(x[i - 1]);
			i--;
			index--;
		}
		while (j > 0)
		{
			ans.push_back(y[j - 1]);
			j--;
			index--;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";

		return ans;
	}
	string shortestCommonSupersequence(string str1, string str2)
	{
		return shortestCommonSupersequence1(str1, str2);
	}
};
