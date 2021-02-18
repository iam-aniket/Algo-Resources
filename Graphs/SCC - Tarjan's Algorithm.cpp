int SCCcount = 0;

void dfs(int& timer, int node, int n, vector<int> adj[], vector<int>& low, vector<int>& in, vector<bool>& vis, vector<bool>& onStack, stack<int>& s)
{
	vis[node] = 1;
	in[node] = low[node] = timer++;
	onStack[node] = 1;
	s.push(node);

	for (auto i : adj[node])
	{
		if (vis[i] == false)
		{
			dfs(timer, i, n, adj, low, in, vis, onStack, s);
			low[node] = min(low[node], low[i]);
		}
		else if (onStack[i] == true) {
			low[node] = min(low[node], in[i]);
		}
	}

	if (in[node] == low[node])
	{
		SCCcount++;
		cout << "SCC #" << SCCcount << " : ";
		int x;
		//Pop till we get the node
		while (1)
		{
			x = s.top();
			s.pop();
			cout << x << " ";
			onStack[x] = 0;
			if (x == node)
				break;
		}
		nl;
	}
}
void tarjanSCC(vector<int> adj[], int n)
{
	stack<int> s;

	vector<int> low(n + 1, 0), in(n + 1, 0);
	vector<bool> vis(n + 1, 0), onStack(n + 1, 0);

	int timer = 1;
	rep(i, 0, n)
	if (vis[i] == false)
	{
		//cout << "Start SCC call at " << i << "\n";
		dfs(timer, i, n, adj, low, in, vis, onStack, s);
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
		}
		tarjanSCC(adj, n);
	}
	return 0;
}
