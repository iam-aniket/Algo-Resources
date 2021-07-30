//LPS = LCS bw (given s) string and (reversed s) string
class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return 1;

        //return LPSusingLCS(s);
        return ArrayTopDown(s);
    }
    int LPSusingLCS(string x)
    {
        string y = x;
        reverse(y.begin(), y.end());
        int m = x.size(), n = y.size();
        int dp[m + 1][n + 1];
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < m + 1; i++)
            for (int j = 0; j < n + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    //Similar method but using two pointer approach instead of using 2 strings
    int topDown(string s)
    {
        int n = s.length();
        int dp[n + 2][n + 2];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n + 1; i++)
            dp[i][i] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            //This is just reversed string order in-place
            for (int j = n; j > 0; j--)
            {
                if (s[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j + 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n][1];
    }
    //O(n^2) TC but space optimized to O(n) SC
    int ArrayTopDown(string s)
    {
        int n = s.length();
        int dp[n] = {0};

        // Pick starting point
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1;// Initialization
            int prev = 0;

            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    // value a[j] is depend upon previous unupdated value of a[j-1]
                    // but in previous loop value of a[j-1] is changed.
                    // To store the unupdated value of a[j-1] prev variable
                    // is used.
                    int temp = a[j];
                    a[j] = prev + 2;
                    prev = temp;
                }
                else
                {
                    prev = a[j];
                    a[j] = max(a[j - 1], a[j]);
                }
            }
        }
        return a[n - 1];
    }
};
