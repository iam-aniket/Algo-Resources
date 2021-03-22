//Min deletion is n - LPS
//Min insertion Q also n - LPS
class Solution {
public:
	int minInsertions(string s)
	{
		int n = s.length();
		int a[n];

		// Pick starting point
		for (int i = n - 1; i >= 0; i--)
		{
			int prev = 0;

			for (int j = i; j < n; j++)
			{
				if (j == i)
					a[j] = 1;

				else if (s[i] == s[j])
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
		//Finding LPS and then return string length n - LPS length
		return n - a[n - 1];
	}
};
