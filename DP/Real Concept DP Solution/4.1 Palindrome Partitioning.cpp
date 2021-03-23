//O(n^2) TC and O(n^2) SC

//First build palindrome matrix of substring partitions
//Then find min cuts till index i
class Solution {
public:
	int palindromicPartitionMCM(string str, int n)
	{
		int C[n];
		bool P[n][n];

		int i, j, k, L; // different looping variables

		// Every substring of length 1 is a palindrome
		for (i = 0; i < n; i++)
			P[i][i] = true;

		/* L is substring length. Build the solution in bottom up manner by
		   considering all substrings of length starting from 2 to n. */
		for (L = 2; L <= n; L++)
		{
			// For substring of length L, set different possible starting indexes
			for (i = 0; i < n - L + 1; i++)
			{
				j = i + L - 1; // Set ending index

				// If L is 2, then we just need to compare two characters. Else
				// need to check two corner characters and value of P[i+1][j-1]
				if (L == 2)
					P[i][j] = (str[i] == str[j]);
				else
					P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
			}
		}

		for (i = 0; i < n; i++)
		{
			if (P[0][i] == true)
				C[i] = 0;
			else
			{
				C[i] = INT_MAX;
				for (j = 0; j < i; j++)
				{
					if (P[j + 1][i] == true && 1 + C[j] < C[i])
						C[i] = 1 + C[j];
				}
			}
		}

		// Return the min cut value for complete string. i.e., str[0..n-1]
		return C[n - 1];
	}
	int palindromicPartition(string str)
	{
		return palindromicPartitionMCM(str, str.size());
	}
};

/////////////////////////////////////////////////////////////////////////////
////////////////////////////Memoized approach - what wrong?//////////////////
/////////////////////////////////////////////////////////////////////////////
int dp[1001][1001];
class Solution {
public:
	bool isPalindrome(string s, int i , int j)
	{
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	int palindromicPartitionMCM(string str, int i , int j)
	{
		if (i >= j || isPalindrome(str, i, j))
			return 0;

		if (dp[i][j] != -1)
			return dp[i][j];

		int ans = INT_MAX;

		for (int k = i; k < j; k++)
		{
			int left = 0, right = 0;
			if (dp[i][k] != -1)
				left = dp[i][k];
			else
			{
				left = palindromicPartitionMCM(str, i, k);
				dp[i][k] = left;
			}
			if (dp[k + 1][j] != -1)
				right = dp[k + 1][j];
			else
			{
				right = palindromicPartitionMCM(str, k + 1, j);
				dp[k + 1][j] = right;
			}
			int temp = 1 + left + right;
			//int temp = 1 + palindromicPartitionMCM(str, i, k) + palindromicPartitionMCM(str, k + 1, j);
			ans = min(ans, temp);
		}

		dp[i][j] = ans;

		return dp[i][j];
	}
	int palindromicPartition(string str)
	{
		memset(dp, -1, sizeof(dp));
		return palindromicPartitionMCM(str, 0, str.size() - 1);
	}
};
