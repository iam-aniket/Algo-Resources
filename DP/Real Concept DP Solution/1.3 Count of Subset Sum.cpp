int knapsackCountSubsetSum(vector<int> arr, int sum)
{
	int n = arr.size(), sum = 0, minDiff = INT_MAX;
	int dp[n + 1][sum + 1];

	//Initialization changed to 1(int){count value}
	for (int i = 0; i < n + 1; i++)
		dp[i][0] = 1;

	for (int i = 1; i < sum + 1; i++)
		dp[0][i] = 0;

	for (int i = 1; i < n + 1; i++) //Note : i Started from 1
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)//Only add + instead of ||
				dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];
}
