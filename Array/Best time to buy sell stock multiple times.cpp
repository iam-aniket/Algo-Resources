class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() == 1)
			return 0;
		int ans = 0;
		for (int i = 0; i < prices.size() - 1; i++)
		{
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
			{
				i++;
			}
            int buy = 0;
            if(i < prices.size() - 1)
            buy = prices[i];

            i++;
			
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
			{
				i++;
			}
            int sell = 0;
            if(i < prices.size())
                sell = prices[i];
			ans += (sell - buy);
		}
		return ans;
	}
};
