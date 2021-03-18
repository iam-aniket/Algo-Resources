int knapsackMinSubsetSumDifference(vector<int> arr)
{
	int n = arr.size(), sum = 0, minDiff = INT_MAX;
	bool dp[n + 1][sum + 1];

	for (int i = 0; i < n; i++)
		sum += arr[i];

	for (int i = 0; i < n + 1; i++)
		dp[i][0] = true;

	for (int i = 1; i < sum + 1; i++)
		dp[0][i] = false;

	for (int i = 1; i < n + 1; i++) //Note : i Started from 1
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	// Find the largest i such that dp[n][i]
	// is true where i loops from sum/2 t0 0
	for (i = sum / 2; i >= 0; i--)
	{
		if (dp[n][i] == 1)
		{
			minDiff = abs(sum - 2 * i);
			break;
		}
	}
	return minDiff;
}
