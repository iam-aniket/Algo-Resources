#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define per(i,a) for(int i = a; i >= 0; i--)
#define lli long long
#define pb push_back
#define mp make_pair
#define nl cout<<"\n"
#define ff first
#define ss second
#define vi vector<int>
#define pie 3.1415926535
#define mx(a,n) *max_element(a,a+n)
#define mn(a,n) *min_element(a,a+n)
#define aop(a,n) rep(i,0,n) cout<<a[i]<<" ";nl
#define aip(a,n) rep(i,0,n) cin>>a[i]
#define so(a,n) sort(a,a+n)
#define sodesc(a,n) sort(a,a+n,sortbydesc)
#define tc int t = 1;cin>>t;while(t--)

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
bool sortbydesc(int &a, int &b)
{	return a > b;	}

void dfs(stack<int>& s, vector<bool>& vis, vector<pair<int, int>> adj[], int n, int node)
{
	vis[node] = 1;
	for (auto it : adj[node])
		if (vis[it.ff] == 0)
			dfs(s, vis, adj, n, it.ff);
	s.push(node);
}

vector<int> topologicalSort(int n, vector<pair<int, int>> adj[])
{
	vector<int> v;
	stack<int> s;

	vector<bool> visited(n + 1, 0);

	for (int i = 0; i < n; i++)
		if (visited[i] == 0)
			dfs(s, visited, adj, n, i);

	cout << "Topo Order : ";
	while (s.empty() == false)
	{
		v.pb(s.top());
		cout << s.top() << " ";
		s.pop();
	}
	nl;
	return v;
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
		int n = 1, e = 1, u = 1, v = 1, w = 0, src = 0;
		cout << "Enter No of nodes : \n";
		cin >> n;
		cout << "Enter no of edges : \n";
		cin >> e;

		vector<pair<int, int>> adj[n + 1];

		rep(i, 0, n + 1)
		adj[i].clear();

		rep(i, 0, e)
		{
			cin >> u >> v >> w;
			adj[u].pb(mp(v, w));
		}

		cout << "Enter source to start for longest path in DAG from : \n";
		cin >> src;

		vector<int> ans = topologicalSort(n, adj);

		//Note : Initialization is with negative INF
		vector<int> dist(n + 1, INT_MAX);
		dist[src] = 0;

		for (auto x : ans)
		{
			if (dist[x] != INT_MAX)
			{
				for (auto y : adj[x])
				{
					if (dist[y.ff] > dist[x] + y.ss)
						dist[y.ff] = dist[x] + y.ss;
					//cout << y.ff << " - " << dist[y.ff] << " \\ ";
				}
				//nl;
			}
		}
		cout << "Distances are : ";
		for (auto x : dist)
			cout << x << " ";
		nl;
	}
	return 0;
}
/*
1
6 10

0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
3 5 1
4 5 -2

1
*/
