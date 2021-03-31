/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. 
Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

Example 1:

Input: arr = [85], pieces = [[85]]
Output: true

Example 2:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]

Example 3:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
*/
class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
	{
		unordered_map<int, vector<int>> mp;
		for (auto x : pieces)
		mp[x[0]] = {x};
		
        for (int i = 0; i < arr.size();)
		{
            if(mp.find(arr[i]) == mp.end())
                return 0;
			int j = i,len = mp[arr[i]].size();
            
			if (len == 1)
            {
                i++;
				continue;
            }
			else
			{
				int x = 0;
				while (len--)
				{
                    if (mp[arr[j]][x++] != arr[i++])
						return 0;
                }
			}
		}
		return 1;
	}
};
