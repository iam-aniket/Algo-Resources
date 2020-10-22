vector<int> adj[101];                        //GLOBAL Declaration

bool DIRcycleDFS(int node, bool vis[], bool rec[])
{
	if (vis[node] == false)
	{
		vis[node] = true;
		rec[node] = true;

		for (auto x : adj[node])
		{
			if (!vis[x] && DIRcycleDFS(x, vis, rec)) return true;
			else if (rec[x] == true) return true;
		}
		rec[node] = false;
		return false;
	}
}

//Inside MAIN() function

bool val = 0;
rep(i, 1, n + 1)
{
	if (!vis[i])
		val = DIRcycleDFS(i, vis, rec);
	if (val == 1)
	{
		cout << "Cycle Present from " << i << "\n";
		break;
	}
}
if (val == 0)
    cout << "No cycle\n";
