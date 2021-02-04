void bfs(int n, vector<int> adj[])
{
	vector<int> dist(n + 1, -1);
	dist[1] = 0;

	vector<int> visited(n + 1, 0);
	visited[1] = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (temp == n)
		{
			cout <<  dist[n] << "\n";
			break;
		}
		for (auto x : adj[temp])
		{
			if (!visited[x])
			{
				visited[x] = 1;
				dist[x] = dist[temp] + 1;
				q.push(x);
			}
		}
	}
}
snakeAndLadder(int N, unordered_map<int, int> move)
{
	int n = N * N;
	vector<int> adj[n + 1];

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 6 && i + j <= n; j++)
		{
			int src = i;
			//Since move[i+j] --> reach that position
			//move[move[i+j]] --> checks if any other snake/ladder at that position
			int dst = move[i + j] ? move[i + j] + (move[move[i + j]] ? move[move[i + j]] : 0) : i + j;
			adj[src].pb(dst);
		}
	}
	/*rep(i, 0, n)
	{
		for (auto x : adj[i])
			cout << x << " - ";
		nl;
	}*/
	bfs(n, adj);
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
		cout << "Enter board length : (n * n) board : \n";
		cin >> n;
		cout << "Enter no of ladders or snake : \n";
		cin >> e;

		unordered_map<int, int> move;
		rep(i, 0, e)
		{
			//cout << "Enter start and end pos : \n";
			cin >> u >> v;
			move[u] = v;
		}
		snakeAndLadder(n, move);
	}
	return 0;
}
