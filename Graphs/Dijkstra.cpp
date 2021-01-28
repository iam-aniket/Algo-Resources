//Input format must be changed for Dijkstra
//Since its weighted graph - used as vector<pair<int,int>> adj[n+1];

void dijkstra(vector<pair<int, int>> adj[], int n, int start)
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
		cout << "From " << start << " to i = " << i << " = " << dist[i] << "\n";
	nl;
}
/*
DIJKSTRA Main()
/////////////////////////
tc
	{
		int n = 1, e = 1, u = 1, v = 1, w = 1, start = 0;
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

		cin >> start;
		dijkstra(adj, n, start);
	}
/////////////////////////
*/
