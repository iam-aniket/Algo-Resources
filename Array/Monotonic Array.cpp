class Solution {
public:
    bool isMonotonic(vector<int>& a) 
    {
        bool incr = 1,decr = 1;
        for(int i = 0; i < a.size()-1;i++)
        {
            if(a[i] > a[i+1])
                incr = 0;
            if(a[i] < a[i+1])
                decr = 0;
        }
        return incr || decr;
    }
};
