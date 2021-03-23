int dp[1001][1001];
class Solution {
public:
	int mcm(int arr[], int i, int j)
	{
		if (i >= j)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];

		int ans = INT_MAX;

		for (int k = i; k < j; k++)
		{
			int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i] * arr[k + 1] * arr[j + 1];
			ans = min(ans, temp);
		}
		dp[i][j] = ans;
		return dp[i][j];
	}
	int matrixMultiplication(int N, int arr[])
	{
		memset(dp, -1, sizeof(dp));
		return mcm(arr, 0, N - 2);
	}
};
