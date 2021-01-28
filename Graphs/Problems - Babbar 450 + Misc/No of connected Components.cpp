#define rep(i,a,n) for(int i = a; i < n; i++)

class Solution {
public:
	void DFS(list<int> adj[], vector<bool> &vis, int n, int node)
	{
		vis[node] = 1;
		for (auto i : adj[node])
			if (!vis[i])
				DFS(adj, vis, n, i);
	}
	int makeConnected(int n, vector<vector<int>>& connections)
	{
		if (connections.size() < n - 1)
			return -1;

		int ct = 0;
		list<int> adj[n + 1];
		vector<bool> vis(n + 1, 0);

		for (auto i : connections)
		{
			int u = i[0], v = i[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		rep(i, 0, n + 1)
		vis[i] = 0;

		DFS(adj, vis, n, 0);

		rep(i, 0, n)
		if (!vis[i])
		{
			DFS(adj, vis, n, i);
			ct++;
		}
		return ct;
	}
};
