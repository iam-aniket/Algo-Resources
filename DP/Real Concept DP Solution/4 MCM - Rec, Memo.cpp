int dp[1001][1001];
class Solution {
public:
	int mcmMemoized(int arr[], int i, int j)
	{
		if (i >= j)
			return 0;

		if (dp[i][j] != -1)
			return dp[i][j];

		int ans = INT_MAX;

		for (int k = i; k < j; k++)
		{
			int temp = mcmMemoized(arr, i, k) + mcmMemoized(arr, k + 1, j) + arr[i] * arr[k + 1] * arr[j + 1];
			ans = min(ans, temp);
		}

		dp[i][j] = ans;

		return dp[i][j];
	}
	int mcmTopDown(int p[], int n)
	{
		for (int i = 1; i < n; i++)
			dp[i][i] = 0;

		// L is chain length.
		for (int L = 2; L < n; L++)
		{
			for (int i = 1; i < n - L + 1; i++)
			{
				int j = i + L - 1;
				dp[i][j] = INT_MAX;

				for (int k = i; k <= j - 1; k++)
				{
					int temp = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
					dp[i][j] = min(dp[i][j], temp);
				}
			}
		}

		return dp[1][n - 1];
	}
	int matrixMultiplication(int N, int arr[])
	{
		memset(dp, -1, sizeof(dp));
		return mcmTopDown(arr, N);
	}
};
