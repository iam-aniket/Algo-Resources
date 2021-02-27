#define Z 100

bool isBipartite(int node, int color[], int n, int adj[][100])
{
	color[node] = 1;
	queue<int> q;
	q.push(node);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int i = 0; i < n; i++)
		{
			if (adj[u][i] && color[i] == -1)
			{
				color[i] = 1 - color[u];
				q.push(i);
			}
			else if (adj[u][i] && color[u] == color[i])
				return false;
		}
	}
	return true;
}
bool twoCliqueDivison(int n, int adj[][Z])
{
	int color[n + 1] = { -1};
	rep(i, 0, n + 1)
	color[i] = -1;

	rep(i, 0, n)
	if (color[i] == 0)
		if (isBipartite(i, color, n, adj) == false)
			return false;
	return true;
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
		int n = 1, e = 1, u = 1, v = 1;
		cout << "Enter No of nodes : \n";
		cin >> n;
		cout << "Enter no of edges : \n";
		cin >> e;

		int adj[n + 1][n + 1] = {0};

		rep(i, 0, e)
		{
			cin >> u >> v;
			adj[u][v] = 1;
			adj[v][u] = 1;
		}

		//Complementing the graph
		int adjComplemented[n + 1][Z] = {0};

		//All values are complemented except
		//diagonal ones
		rep(i, 0, n)
		rep(j, 0, n)
		{
			if (i != j)
				adjComplemented[i][j] = !adj[i][j];
			else
				adjComplemented[i][j] = 0;
		}

		bool ans = twoCliqueDivison(n, adjComplemented);
		if (ans)
			cout << "Yes can be divided in two cliques\n";
		else
			cout << "NO\n";
	}
	return 0;
}
