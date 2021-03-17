//bool dp[n+1][sum+1];
bool knapsackSubsetSum(vector<int> arr, int sum, int n)
{
	//Base Condition changed to initialization

	//If sum is 0 ans is true
	for (int i = 0; i < n + 1; i++)
		dp[i][0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i < sum + 1; i++)
		dp[0][i] = false;


	//Convert Recursive code to loops
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

	return dp[n][sum];
}
