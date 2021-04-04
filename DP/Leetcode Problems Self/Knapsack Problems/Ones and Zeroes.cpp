class Solution {
public:
	vector<vector<vector<int> > >dp;
	int findMaxForm(vector<string>& str, int m, int n)
	{
		dp.resize(size(str), vector<vector<int> >(m + 1, vector<int>(n + 1)));
		return rec(str, 0, m, n);
	}
	int rec(vector<string>& str, int i, int m, int n)
	{
		if (i == str.size())
			return 0;

		if (dp[i][m][n]) return dp[i][m][n];

		int z = count(begin(str[i]), end(str[i]), '0'), o = size(str[i]) - z;

		//Choosing or not choosing
		if (m >= z && n >= o)
			dp[i][m][n] = max(1 + rec(str, i + 1, m - z, n - o), rec(str, i + 1, m, n));
        //Cant choose if not available zeros and ones
        else
            dp[i][m][n] = rec(str, i + 1, m, n);

		return dp[i][m][n];
	}
};
