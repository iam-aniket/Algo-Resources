bool bipartite = 0;

void dfs(int node, int cur, vector<int>& color, vector<int> adj[], vector<int>& vis)
{
	vis[node] = 1;
	color[node] = cur;
	for (auto x : adj[node])
	{
		if (!vis[x])
			dfs(x, cur == 1 ? 2 : 1, color, adj, vis);

		else if (color[x] == cur)
		{
			bipartite = 1;
			return;
		}
	}
}
/*bool bipartiteDfs(int node, int cur)
{
	vis[node] = 1;
	color[node] = cur;
	for (auto x : adj[node])
	{
		if (!vis[x])
		{
			if (dfs(x, cur ^ 1) == false)
				return false;
		}
		else if (color[x] == color[node])
			return false;
	}
	return true;
}*/
int main()
{
	tek;
#ifndef ONLINE_JUDGE
	freopen("IP.txt", "r", stdin);
	freopen("OP.txt", "w", stdout);
#endif
	tc
	{
		int n = 1, e = 1, u = 1, v = 1;
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

		int cur = 1;
		vector<int> color(n + 1, -1), vis(n + 1, 0);

		rep(i, 0, n)
		if (vis[i] == 0)
			dfs(i, cur, color, adj, vis);

		if (bipartite)
			cout << "This is NOT a bipartite graph\n";
		else
			cout << "This is a bipartite graph\n";
	}
	return 0;
}
