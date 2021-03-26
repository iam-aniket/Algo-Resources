class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        //256 is max ASCII value for the req range
        int m1[256] = {0},m2[256] = {0};
        for(int i = 0; i < s.size();i++)
        {
            if(m1[s[i]] != m2[t[i]])
            {
                    return false;
            }
            else
            {
                m1[s[i]] = i + 1;
                m2[t[i]] = i + 1;
            }
        }
        return true;
    }
};
