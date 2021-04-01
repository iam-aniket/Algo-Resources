class Solution {
public:
	int numDecodings(string s)
	{
		int n = s.size();
		int dp[n + 1];

		if (s[0] == '0')return 0;
		dp[0] = 1;

		if ((s[1] >= '1' && s[1] <= '6') && (s[0] == '1' || s[0] == '2'))
			dp[1] = 2;
		else if ((s[1] >= '7' && s[1] <= '9') && (s[0] == '1'))
			dp[1] = 2;
		else if (s[1] == '0')
		{
			if (s[0] == '1' || s[0] == '2')
				dp[1] = 1;
			else
				return 0;
		}
		else
			dp[1] = 1;


		for (int i = 2; i < n; i++)
		{
			if ((s[i] >= '1' && s[i] <= '6') && (s[i - 1] == '1' || s[i - 1] == '2'))
				dp[i] = dp[i - 1] + dp[i - 2];

			else if ((s[i] >= '7' && s[i] <= '9') && (s[i - 1] == '1'))
				dp[i] = dp[i - 1] + dp[i - 2];

			else if (s[i] == '0')
			{
				if (s[i - 1] == '1' || s[i - 1] == '2')
					dp[i] = dp[i - 2];
				else
					return 0;
			}
			else
				dp[i] = dp[i - 1];
		}


		return dp[n - 1];
	}
};
