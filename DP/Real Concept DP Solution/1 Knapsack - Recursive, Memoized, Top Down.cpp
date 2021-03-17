//Any DP Problem(3 steps):-
//1) Recursive Solution
//2) Memoize above soln (Bottom-Up Soln)
//3) Top-Down DP Table soln

//1) To do Recursive solution
//* Draw Choice Diagram properly - then convert to code
//* Remember Base Condition - Smallest Valid Input possible


//In main() call:-
//int ans = knapsackRecursive(weight,val,w,n);
int knapsackRecursive(vector<int> weight, vector<int> val, int w, int n)
{
	//Base Case : Smallest Valid IP
	if (w == 0 || n == 0)
		return 0;

	//If Weight is less than current bag weight
	//2 Choices:- Select Item or Not Select
	//Take Max of Both in REC Way
	if (weight[n - 1] <= w)
	{
		return max(val[n - 1] + knapsackRecursive(weight, val, w - weight[n - 1], n - 1),
		           knapsackRecursive(weight, val, w, n - 1));
	}
	//Item weight is larger than bag weight so cant select - so skip
	else
		return knapsackRecursive(weight, val, w, n - 1);
}

//2 Memoized Solution - Bottom Up
//(Recursive calls + DP table to store reccuring )

//* Form a table to store precomputed values - (initialsed to -1)
//* Table is formed between values that change in recursive calls
//* here n and w change so dp[n][w] = {-1};
//* dp table can be global since values are small; so int dp[100][1000] = {-1};

int knapsackMemoized(vector<int> weight, vector<int> val, int w, int n)
{
	if (w == 0 || n == 0)
		return 0;

	//To check if value already present
	if (dp[n][w] == -1)
		return dp[n][w];

	if (weight[n - 1] <= w)
	{
		//Store and then return
		dp[n][w] = max(val[n - 1] + knapsackRecursive(weight, val, w - weight[n - 1], n - 1),
		               knapsackRecursive(weight, val, w, n - 1));
		return dp[n][w];
	}
	else
	{
		//Store and then return
		dp[n][w] = knapsackRecursive(weight, val, w, n - 1);
		return dp[n][w];
	}
}

//3) Top Down Solution
//(Only DP Table & no recursive calls) -> Iterative Totally
//(In this solution only we get Subproblems approach)

//* Base condition - Is initialization in DP Table
//* Recursive transformed to Table values

//int dp[100][1000]; as global
int knapsackTopDown(vector<int> weight, vector<int> val, int w, int n)
{
	//Base Condition changed to initialization
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	//Convert Recursive code to loops
	for (int i = 1; i < n + 1; i++) //Note : i Started from 1
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (wt[i - 1] <= j)
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][w];
}

//Top Down is BEST although Bottom Up(Memoized soln) is also of same complexity
//but Bottom Up uses recursion and sometimes recursive stack space may limit out.

//Top Down Vs Bottom UP
//TC : Same
//SC : B-U has extra REC Stack Space
