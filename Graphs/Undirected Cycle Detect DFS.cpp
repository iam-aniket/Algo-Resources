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

int main()
{
    int val = cycleDFS(1, vis, 0);//Start node 1 has parent 0
		if (val)
			cout << "\nCycle Present!\n\n";
		else
			cout << "\nNo Cycle!\n";
}
