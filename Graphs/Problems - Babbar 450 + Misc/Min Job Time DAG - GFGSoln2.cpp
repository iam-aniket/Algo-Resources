//https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/
void order(int n, list<int> adj[], vector<int> inDeg)
{
	queue<int> q;
	vector<int> job(n + 1, 0);
	rep(i, 0, n)
	if (inDeg[i] == 0) {
		q.push(i);
		job[i] = 1;
	}
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (auto x : adj[temp])
		{
			inDeg[x]--;
			if (job[x] < job[temp] + 1)
				job[x] = max(job[x], job[temp] + 1);
			if (inDeg[x] == 0)
				q.push(x);
		}
	}
	rep(i, 1, n + 1)
	cout << job[i] << " ";
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
		vector<int> inDeg(n + 1, 0);
		list<int> adj[n + 1];
		rep(i, 0, e)
		{
			int u = 0, v = 0;
			cin >> u >> v;
			adj[u].pb(v);
			inDeg[v]++;
		}
		order(n, adj, inDeg);
	}
	return 0;
}
