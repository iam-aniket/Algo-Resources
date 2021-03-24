//O(n) TC + O(1) SC
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Boyer Moore Voting Algo
        int count = 0;
        int ans = 0;
        for(auto x : nums)
        {
            if(count == 0)
                ans = x;
            
            if(count > nums.size()/2)
                return ans;
            
            count += (x == ans) ? 1 : -1;
        }
        return ans;
    }
};
