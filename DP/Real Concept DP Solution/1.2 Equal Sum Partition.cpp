//Same to Subset sum

//If Sum of array is odd -> Return False since 2 parition cannot have same value

//If sum of array is even
//And if sum/2 is a possible subset sum -> return true

class Solution
{
public:

	bool canPartition(vector<int>& arr)
	{
		int n = arr.size();
		int sum = 0;

		for (int i = 0; i < n; i++)
			sum += arr[i];

		if (sum % 2)
			return false;

		else //If Even Check if sum/2 is a possible subset sum
		{
			bool dp[n + 1][sum + 1];

			//Check if half sum is possible
			//Since the other half automatically will be equal(ie; sum/2)
			sum = sum / 2;

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

			return dp[n][sum];//Since sum is already changed as sum/2
		}
	}
};
