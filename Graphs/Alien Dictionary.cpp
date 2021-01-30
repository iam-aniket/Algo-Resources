#define pb push_back
#define rep(i,a,n) for(int i = a; i < n; i++)
class Solution {
public:
	void dfs(stack<int>& s, vector<bool>& vis, list<int> adj[], int n, int node)
	{
		vis[node] = 1;
		for (auto it : adj[node])
			if (vis[it] == 0)
				dfs(s, vis, adj, n, it);
		s.push(node);
	}
	vector<int> topologicalSort(int n, list<int> adj[])
	{
		vector<int> v;
		stack<int> s;

		vector<bool> visited(n + 1, 0);

		for (int i = 0; i < n; i++)
			if (visited[i] == 0)
				dfs(s, visited, adj, n, i);

		while (s.empty() == false)
		{
			v.pb(s.top());
			s.pop();
		}
		return v;
	}
	string findOrder(string dict[], int n, int k)
	{
		list<int> adj[k + 1];
		rep(i, 0, n - 1)
		{
			string x = dict[i], y = dict[i + 1];
			int minlen = min(x.length(), y.length());
			rep(j, 0, minlen)
			{
				if (x[j] != y[j])
				{
					adj[x[j] - 'a'].push_back(y[j] - 'a');
					break;
				}
			}
		}
		string s;
		vector<int> v = topologicalSort(k, adj);
		rep(i, 0, v.size())
		    s += (v[i]+'a');
		return s;
	}
};
