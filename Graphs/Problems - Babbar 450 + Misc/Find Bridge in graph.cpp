//https://leetcode.com/problems/critical-connections-in-a-network/
vector<int> vis, in, low, atpoint;
int timer = 0;
bool flag = 0;
vector<vector<int>> ans;

void dfs(int node, vector<int> adj[], int parent = -1)
{
	vis[node] = 1;
	low[node] = in[node] = timer++;
	for (auto child : adj[node])
	{
		if (child == parent)
			continue;
		if (vis[child] == 1) //Back Edge
			low[node] = min(low[node], in[child]);
		else
		{
			dfs(child, adj, node);
			low[node] = min(low[node], low[child]);
			if (low[child] > in[node])
			{
				ans.push_back({child, node});
			}
		}
	}
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connect)
{
	vis.assign(n, false);
	in.assign(n, -1);
	low.assign(n, -1);

	int e = connect.size();

	vector<int> adj[n + 1];
	for (int i = 0; i < e; i++)
	{
		int u = connect[i][0], v = connect[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i])
			dfs(i, adj);
	}
	return ans;
}
