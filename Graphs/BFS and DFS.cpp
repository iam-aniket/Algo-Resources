#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define tc int t = 1;cin>>t;while(t--)

using namespace std;

list<int> adj[100 + 1];
vector<bool> vis(100 + 1, 0);

void BFS(int n, int start)
{
	bool vis[n + 1] = {0};
	queue<int> q;
	q.push(start);
	vis[start] = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (auto it : adj[x])
			if (!vis[it])
			{
				q.push(it);
				vis[it] = 1;
			}
	}
}
void DFS(vector<bool> &vis, int n, int node)
{
	cout << node << " ";
	vis[node] = 1;
	for (auto it : adj[node])
		if (!vis[it])
			DFS(vis, n, it);
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

		rep(i, 0, n + 1)
		adj[i].clear();

		rep(i, 0, e)
		{
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		cout << "BFS : ";
		BFS(n, 1);

		rep(i, 0, n + 1)
		vis[i] = 0;

		cout << "\nDFS : ";
		DFS(vis, n, 1);

		//Remaining any nodes that are not visited
		//----->//Mostly required only for Directed Graph
		//Since only no indegree nodes = 0
		//will be left in that case
		rep(i, 1, n + 1)
		if (!vis[i])
			DFS(vis, n, i);
	}
}
/*
1
6
6
5 0
5 2
4 0
4 1
2 3
3 1
*/
/*
2
7
11
1 2
1 3
1 7
2 3
2 4
2 5
3 6
3 7
4 5
5 6
6 7
3
2
1 2
2 3
*/
