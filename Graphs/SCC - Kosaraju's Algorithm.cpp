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
//Standard dfs on original graph
void dfs(int n, std::vector<int> adj[], std::vector<bool>& vis, int node, stack<int>& s)
{
	vis[node] = 1;
	for (auto x : adj[node])
		if (!vis[x])
			dfs(n, adj, vis, x, s);
	s.push(node);
}
//Perform Dfs on reversed graph
void dfsRev(int n, std::vector<int> adjRev[], std::vector<bool>& vis, int node)
{
	cout << node << " ";
	vis[node] = 1;
	for (auto x : adjRev[node])
		if (!vis[x])
			dfsRev(n, adjRev, vis, x);
}
void scc(int n, vector<int> adj[], vector<int> adjRev[])
{
	stack<int> s;
	std::vector<bool> vis(n + 1, 0);

	//Construct stack - dfs
	rep(i, 0, n)
	if (!vis[i])
		dfs(n, adj, vis, i, s);

	rep(i, 0, n)
	vis[i] = 0;

	//Perform dfs on reversed graph from stack
	while (!s.empty())
	{
		cout << "SCC : ";
		if (!vis[s.top()])
			dfsRev(n, adjRev, vis, s.top());
		nl;
		s.pop();
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

		//adjRev - to store graph in reverse manner
		vector<int> adj[n + 1], adjRev[n + 1];

		rep(i, 0, n + 1)
		{
			adj[i].clear();
			adjRev[i].clear();
		}

		rep(i, 0, e)
		{
			cin >> u >> v;
			adj[u].pb(v);
			adjRev[v].pb(u);
		}

		scc(n, adj, adjRev);
	}
	return 0;
}
/*
1
6
5
5
0 2
0 3
1 0
2 1
3 4
*/
/*
1
11
17
0 1
0 3
1 2
1 4
2 0
2 6
3 2
4 5
4 6
5 6
5 7
5 8
5 9
6 4
7 9
8 9
9 8
*/
