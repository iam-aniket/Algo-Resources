bool dfs(int src, int k, std::vector<int>& path, std::vector<bool>& vis, std::vector<pair<int, int>> adj[])
{
	if (k <= 0)
		return 1;
	for (auto x : adj[src])
	{
		if (vis[x.ss])
			continue;
		if (x.ff >= k)
			return 1;
		else
		{
			vis[x.ss] = 1;
			path.pb(x.ss);
			if (dfs(x.ss, k - x.ff, path, vis, adj))
				return 1;
			path.pop_back();
			vis[x.ss] = 0;
		}
	}
	return 0;
}
bool pathMoreThanK(int src, int k, int n, vector<pair<int, int>> adj[])
{
	vector<bool> vis(n + 1, 0);
	vector<int> path;
	path.pb(src);
	vis[src] = 1;

	bool ans = dfs(src, k, path, vis, adj);

	/*
	cout<<"Path : "
		for (auto x : path)
			cout << x << " ";
	nl;
	*/

	return ans;
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
		int n = 1, e = 1, u = 1, v = 1, w = 1, k = 0, start = 0;
		cin >> n;
		cin >> e;
		vector<pair<int, int>> adj[n + 1];
		rep(i, 0, n + 1)
		adj[i].clear();
		rep(i, 0, e)
		{
			cin >> u >> v >> w;
			adj[u].pb(mp(w, v));
			adj[v].pb(mp(w, u));
		}
		cout << "Enter source vertex(src) and max length path(k) : \n";
		cin >> start >> k;

		bool val = pathMoreThanK(start, k, n, adj);
		cout << val << "\n";
	}
	return 0;
}
/*
1
9 14
0 1 5
0 7 9
1 2 9
1 7 12
2 3 8
2 8 3
2 5 10
3 4 10
3 5 15
4 5 11
5 6 3
6 7 2
6 8 7
7 8 8

0 68
*/

/*
0 70 : ANS : NO
*/
