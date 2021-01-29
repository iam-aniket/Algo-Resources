//https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
void dfs(stack<int>& s, vector<bool>& vis, list<int> adj[], int n, int node)
{
	vis[node] = 1;
	for (auto it : adj[node])
		if (vis[it] == 0)
			dfs(s, vis, adj, n, it);
	s.push(node);
}
vector<int> topologicalSort(int n, list<int> adj[])
{
	vector<int> v;
	stack<int> s;

	vector<bool> visited(n + 1, 0);

	for (int i = 0; i < n; i++)
		if (visited[i] == 0)
			dfs(s, visited, adj, n, i);

	while (s.empty() == false)
	{
		v.pb(s.top());
		cout << s.top() << " ";
		s.pop();
	}
	nl;
	return v;
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
		cin >> n;
		cin >> e;
		list<int> adj[n + 1];
		rep(i, 0, e)
		{
			int u = 0, v = 0;
			cin >> u >> v;
			adj[u].pb(v);
		}
		vector<int> par(n + 1, -1);
		rep(i, 0, n)
		{
			if (adj[i].size() != 0)
			{
				for (auto x : adj[i])
					par[x] = max(i, par[x]);
			}
		}
		vector<int> v = topologicalSort(n, adj);
		int ans[n + 1] = {0};
		for (auto x : v)
		{
			if (par[x] == -1)
				ans[x] = 1;
			else
				ans[x] = ans[par[x]] + 1;
		}
		rep(i, 1, n + 1)
		cout << ans[i] << " ";
	}
	return 0;
}
