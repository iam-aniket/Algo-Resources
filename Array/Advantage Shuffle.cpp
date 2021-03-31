/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]

*/
class Solution {
public:
	vector<int> advantageCount(vector<int>& a, vector<int>& b)
	{
		sort(a.begin(), a.end());

		for (int i = 0; i < b.size(); i++)
		{
			auto pos = upper_bound(a.begin(), a.end(), b[i]);

			if (pos != a.end())
			{
				b[i] = *pos;
				a.erase(pos);
			}
			else
			{
				b[i] = a[0];
				a.erase(a.begin());
			}
		}
		return b;
	}
};
