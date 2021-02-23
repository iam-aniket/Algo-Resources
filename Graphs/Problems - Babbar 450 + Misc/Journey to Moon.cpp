bool sortbydesc(int &a, int &b)
{	return a > b;	}

int dfs(int node, std::vector<int>& vis, std::vector<int> adj[], int n, int& ans)
{
	ans++;
	vis[node] = 1;
	for (auto x : adj[node])
		if (!vis[x])
			ans = dfs(x, vis, adj, n, ans);
	return ans;
}

int CC(std::vector<int> adj[], int n)
{
	int ans = 0, ct = 0;
	std::vector<int> vis(n + 1, 0), result;

	rep(i, 0, n)
	if (!vis[i])
	{
		ct++;
		ans = 0;
		dfs(i, vis, adj, n, ans);
		result.pb(ans);
		//cout << "No of nodes = " << ans << "\n";
	}

	int s = result.size();
	int ax = 0;

	sort(result.begin(), result.end(), sortbydesc);

	for (auto x : result)
		cout << x << " ";
	nl;

	for (int i = 0; i < s - 1; i++)
	{
		int temp = result[i];

		if (temp == 1)
		{
			int x = (s - i);
			temp = 0;
			temp = (x * (x - 1)) / 2;
			ax += temp;
			break;
		}
		else
		{
			int j = i + 1, val = 0;
			while (j < s && result[j] != 1)
			{
				val += result[j];
				j++;
			}
			val += (s - j);

			temp *= val;
		}
		ax += temp;
	}
	return ax;
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
			adj[v].pb(u);
		}

		int val = CC(adj, n);
		cout << "Ans = " << val << "\n";

	}
	return 0;
}
