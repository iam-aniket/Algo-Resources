bool DIRcycleDFS(list<int> adj[], int node, vector<int>& vis, bool rec[])
{
	if (vis[node] == false)
	{
		vis[node] = true;
		rec[node] = true;

		for (auto x : adj[node])
		{
			if (!vis[x] && DIRcycleDFS(adj, x, vis, rec)) return true;
			else if (rec[x] == true) return true;
		}
		rec[node] = false;
		return false;
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
		int n = 0, e = 0;
		cin >> n >> e;

		list<int> adj[n + 1];
		rep(i, 0, e)
		{
			int u = 0, v = 0;
			cin >> u >> v;
			adj[u].pb(v);
		}
		int f = 0;
		bool rec[n + 1] = {0};
		vector<int> vis(n + 1, 0);
		rep(i, 0, n)
		{
			if (!vis[i])
			{
				bool x = DIRcycleDFS(adj, 1, vis, rec);
				if (x)
				{
					f = 1;
					cout << "Not Possible\n";
					break;
				}
				else
					continue;
			}

		}
		if (f == 0)
			cout << "Possible\n";
	}
	return 0;
}
