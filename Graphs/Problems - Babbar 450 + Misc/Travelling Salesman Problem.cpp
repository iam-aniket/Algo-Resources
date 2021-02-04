void tsp(int n, vector<pair<int, int>> adj[], vector<bool> &visited, int node, int count, int cost, int& ans)
{
	if (count == n && adj[node][0].ss == 0)
	{
		ans = min(cost + adj[node][0].ff, ans);
		return;
	}

	for (auto x : adj[node])
	{
		if (visited[x.ss] == 0 )
		{
			visited[x.ss] = 1;
			tsp(n, adj, visited, x.ss, count + 1, cost + x.ff, ans);
			visited[x.ss] = 0;
		}
	}
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
		int n = 1, e = 1, u = 1, v = 1, w = 0, start = 0;
		cout << "Enter No of nodes : \n";
		cin >> n;
		cout << "Enter no of edges : \n";
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

		/*rep(i, 0, n)
		{
			for (auto x : adj[i])
				cout << i << " -> " << x.ss << " = " << x.ff << "\n";
			nl;
		}*/

		int ans = INT_MAX;
		vector<bool> visited(n + 1, 0);
		visited[0] = 1;
		tsp(n, adj, visited, 0, 1, 0, ans);
		cout << "Travelling Salesman's Distance = " << ans << "\n";
	}
	return 0;
}
/*
1
4
6
0 1 10
0 3 20
0 2 15
1 2 35
1 3 25
2 3 30
*/
