//https://www.interviewbit.com/problems/snake-ladder-problem/
int ans = 0;
set<int> snake, ladder;
void bfs(vector<int> adj[])
{
	vector<int> vis(101, 0), dist(101, INT_MAX);
	dist[1] = 0;
	vis[1] = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (temp == 100)
		{
			ans = dist[100];
			return;
		}
		for (auto x : adj[temp])
		{
			if (!vis[x])
			{
				vis[x] = 1;
				//VVI - since ladder and snake moves dont increment dist
				if (ladder.find(temp) != ladder.end() || snake.find(temp) != snake.end())
					dist[x] = dist[temp];
				else
					dist[x] = dist[temp] + 1;
				q.push(x);
			}
		}
	}
	ans = dist[100];
}
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
	vector<int> adj[101];
	for (int i = 0; i < 101; i++)
		adj[i].clear();
	ladder.clear();
	snake.clear();
	ans = INT_MAX;


	for (int i = 1; i <= 100; i++)
		for (int j = i + 1; j <= 100 && j <= i + 6; j++)
			adj[i].push_back(j);


	for (int i = 0; i < A.size(); i++)
	{
		int u = A[i][0], v = A[i][1];
		ladder.insert(u);
		//VVI - since if ladder or snake only that path can be taken
		adj[u].clear();
		adj[u].push_back(v);
	}

	for (int i = 0; i < B.size(); i++)
	{
		int u = B[i][0], v = B[i][1];
		snake.insert(u);
		//VVI - since if ladder or snake only that path can be taken
		adj[u].clear();
		adj[u].push_back(v);
	}

	bfs(adj);

	if (ans == INT_MAX)
		return -1;
	else
		return ans;
}
