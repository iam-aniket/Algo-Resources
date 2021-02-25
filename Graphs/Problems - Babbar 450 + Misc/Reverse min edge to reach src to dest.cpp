void dijkstra(vector<pair<int, int>> adj[], int n, int start, int dest)
{
	set<pair<int, int>> s;
	vector<int> dist(n + 1, INT_MAX);
	dist[start] = 0;
	s.insert(mp(0, start));

	while (!s.empty())
	{
		pair<int, int> temp = *(s.begin());
		s.erase(s.begin());
		int wt = temp.ff;
		int u = temp.ss;
		for (auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int wt = (*it).ff;
			int v = (*it).ss;

			if (dist[v] > dist[u] + wt)
			{
				if (dist[v] != INT_MAX)
					s.erase(s.find(mp(dist[v], v)));
				dist[v] = dist[u] + wt;
				s.insert(mp(dist[v], v));
			}

		}
	}
	for (int i = 1; i <= n; i++)
		cout << "From " << start << " to " << i << " : " << dist[i] << "\n";
	nl;
	cout << "Edges to reverse to reach from " << start << " to " << dest << " = " << dist[dest] << "\n";
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
		int n = 1, e = 1, src = 0, dest = 0, u = 1, v = 1, w = 1, start = 0;

		cout << "Enter No of nodes : \n";
		cin >> n;
		cout << "Enter no of edges : \n";
		cin >> e;

		vector<pair<int, int>> adj[n + 1];
		rep(i, 0, n + 1)
		adj[i].clear();

		rep(i, 0, e)
		{
			cin >> u >> v;
			adj[u].pb(mp(0, v));
			adj[v].pb(mp(1, u));
		}
		cout << "Enter source and destination : \n";
		cin >> src >> dest;
		dijkstra(adj, n, src, dest);
	}
	return 0;
}
/*
1
7 7

0 1
2 1
2 3
4 5
5 1
6 3
6 4

0 6
*/
