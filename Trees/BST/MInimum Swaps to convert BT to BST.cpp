vector<int> v;

void inorder(vector<int> a, int index)
{
	// if index is greater or equal to vector size
	if (index >= a.size())
		return;

	//Left node
	inorder(a, 2 * index + 1);

	// push elements in vector
	v.push_back(a[index]);

	//Right node
	inorder(a, 2 * index + 2);
}
int minSwapsToSortArray(vector<int> v)
{
	int n = v.size();

	vector<int> temp = v;
	sort(temp.begin(), temp.end());

	unordered_map<int, int> m;

	for (int i = 0; i < n; i++)
		m[v[i]] = i;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] != temp[i])
		{
			int pos1 = i, pos2 = m[temp[i]];

			swap(v[pos1], v[pos2]);

			count++;

			m[v[pos2]] = pos2;
			m[v[pos1]] = pos1;
		}
		else
			continue;
	}
	return count;
}
int minSwapsBinarytoBST(vector<int> a)
{
	if (a.size() == 0 || a.size() == 1)
		return 0;

	//Store inorder of given Binary Tree
	inorder(a, 0);

	//Count Minimum swaps to sort this inorder array (to get BST)
	int ans = minSwapsToSortArray(v);

	return ans;
}

int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	int n = 0;
	cin >> n;
	
	vector<int> a(n, 0);
	
	rep(i, 0, n)
	cin >> a[i];
	
	int x = minSwapsBinarytoBST(a);
	cout << "Ans = " << x << "\n";
}
/*
7
5 6 7 8 9 10 11
*/
