class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
    	int min = INT_MAX, maxi = 0,n = a.size();
		for (int i = 0; i < n; i++)
		{
			if (a[i] < min)
				min = a[i];
			else
				maxi = max(maxi, a[i] - min);
		}
		return maxi;
    }
};
