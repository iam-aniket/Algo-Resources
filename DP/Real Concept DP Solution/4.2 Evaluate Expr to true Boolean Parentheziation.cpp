unordered_map<string, int > mp;
int evaluateExprTrue(string s, int i, int j, bool isTrue)
{
	if (i > j)
		return true;
	if (i == j)
	{
		if (isTrue == true)
			return s[i] == 'T';
		else
			return s[i] == 'F';
	}

	string temp = to_string(i);
	temp.push_back(' ');
	temp.append(to_string(j));
	temp.push_back(' ');
	temp.append(to_string(isTrue));

	if (mp.find(temp) != mp.end())
		return mp[temp];

	int ans = 0;

	//Note : k incr by 2 since only operators required
	for (int k = i + 1; k <= j - 1; k += 2)
	{
		int leftTrue = evaluateExprTrue(s, i, k - 1, true);
		int leftFalse = evaluateExprTrue(s, i, k - 1, false);
		int rightTrue = evaluateExprTrue(s, k + 1, j, true);
		int rightFalse = evaluateExprTrue(s, k + 1, j, false);

		if (s[k] == '&')
		{
			if (isTrue == true)
				ans += (leftTrue * rightTrue) % 1003;
			else
				ans += ((leftTrue * rightFalse) + (leftFalse * rightFalse) + (leftFalse * rightTrue)) % 1003;
		}
		else if (s[k] == '|')
		{
			if (isTrue == true)
				ans += ((leftTrue * rightFalse) + (leftTrue * rightTrue) + (leftFalse * rightTrue)) % 1003;
			else
				ans += ((leftFalse * rightFalse)) % 1003;
		}
		else if (s[k] == '^')
		{
			if (isTrue == true)
				ans += ((leftFalse * rightTrue) + (leftTrue * rightFalse)) % 1003;
			else
				ans += ((leftFalse * rightFalse) + (leftTrue * rightTrue)) % 1003;
		}
	}
	mp[temp] = ans % 1003;
	return ans % 1003;
}
int Solution::cnttrue(string A)
{
	mp.clear();
	int ans = evaluateExprTrue(A, 0, A.size() - 1, true);
	return ans % 1003;
}
