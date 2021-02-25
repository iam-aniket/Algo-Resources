bool validColor(int i, int node, std::vector<int> colors, std::vector<int> adj[])
{
	bool flag = 0;
	for (auto x : adj[node])
	{
		if (colors[x] == i) {
			flag = 1;
			break;
		}
	}
	return flag;
}

bool assignColorBT(int node, int m, int n, std::vector<int>& colors, std::vector<int> adj[])
{
	if (node == n)
		return true;
	//Note : coloring starts from 1 since uncolor is taken as 0
	for (int i = 1; i <= m; i++)
	{
		bool flag = validColor(i, node, colors, adj);

		if (flag)
			continue;
		else
		{
			colors[node] = i;
			if (assignColorBT(node + 1, m, n, colors, adj) == true)
				return true;
			//Uncolor is 0
			colors[node] = 0;
		}
	}
	return false;
}

bool graphColoring(int n, int m, std::vector<int> adj[])
{
	vector<int> colors(n + 1, 0);

	int src = 0;

	bool val = assignColorBT(src, m, n, colors, adj);

	if (val)
	{
		cout << "Colors are : ";
		rep(i, 0, n)
		cout << colors[i] << " ";
		nl;
		return true;
	}
	else
		return false;
}

int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	tc
	{
		int n = 1, m = 1, e = 1, u = 1, v = 1;
		cout << "Enter No of nodes : \n";
		cin >> n;
		cout << "Enter no of edges : \n";
		cin >> e;

		vector<int> adj[n + 1];

		rep(i, 0, n + 1)
		adj[i].clear();

		rep(i, 0, e)
		{
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		cout << "Enter no of colors : \n";
		cin >> m;

		bool val = graphColoring(n, m, adj);
		if (val)
			cout << "Yes Possible to color with " << m << " colors\n";
		else
			cout << "Not Possible\n";
	}
	return 0;
}
/*
1
4 5

0 1
0 2
0 3
1 2
2 3

3
*/
