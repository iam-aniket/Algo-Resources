bool cycleDFS(int node, vector<bool> &vis, int parent)
{
	vis[node] = true;
	for (auto x : adj[node])
	{
		if (!vis[x])
		{
			if (cycleDFS(x, vis, node))
				return true;
		}
		else if (x != parent)
			return true;
	}
	return false;
}
bool cycleBFS(int start, int n)
{
	bool vis[n + 1] = {0};
	vector<int> parent(n + 1, -1);
	vis[start] = 1;
	queue<int> q;
	q.push(start);
	
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (auto x : adj[temp])
		{
			if (!vis[x])
			{
				vis[x] = 1;
				q.push(x);
				parent[x] = temp;
			}
			else if (parent[temp] != x)
				return true;
		}
	}
	return false;
}
