void bellmanFord(int n, vector<pair<int, pair<int, int>>> adj, int start, int e)
{
	int f = 1;
	vector<int> dist(n + 1, INT_MAX);
	dist[start] = 0;

	//Relax (n-1) times - since from u to v at max (n-1) paths possible
	rep(i, 0, n - 1)
	{
		rep(j, 0, e)
		{
			int u = adj[j].ss.ff;
			int v = adj[j].ss.ss;
			int weight = adj[j].ff;

			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight ;
		}
	}

	//Check if graph has negative edge cycle
	rep(i, 0, e)
	{
		int u = adj[i].ss.ff;
		int v = adj[i].ss.ss;
		int weight = adj[i].ff;

		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			f = 0;
			cout << "Negative weight sum cycle present!";
			break;
		}
	}

	if (f)
	{
		rep(i, 0, n)
		cout << dist[i] << " ";
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

		vector<pair<int, pair<int, int>>> adj;
		rep(i, 0, e)
		{
			cin >> u >> v >> w;
			adj.push_back(mp(w, mp(u, v)));
		}

		cout << "Enter start vertex : \n";
		cin >> start;

		bellmanFord(n, adj, start, e);

	}
	return 0;
}
