//Bad Problem Desc
//Actually : 

/*
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

                           __________
                       ___| Final step
                 _____| 20
            ___ | 15
_________ | 10
First step

I had the same doubt:
Comment from Hlady clears it:
"Another person asked the same question. The destination stair (top of stairs) is actually one step beyond the last step in the array. 
So if you started at '10', you'd have to step on '20' then you'd be able to get to the top with a total cost of 30. The cost to step on the "top of stairs" is zero."
  */

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		int n = cost.size();
		int dp[n];
		for (int i = 0; i < n; i++)
		{
			if (i < 2) dp[i] = cost[i];
			else dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
		}
		return min(dp[n - 1], dp[n - 2]);
	}
};
