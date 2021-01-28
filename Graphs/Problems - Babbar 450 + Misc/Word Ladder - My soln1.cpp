#define rep(i,a,n) for(int i = a; i < n; i++)
class Solution {
public:
	int bfs(list<int> adj[], string beginWord, string endWord, int n, int endPos)
	{
		int start = 0;
		bool vis[5001] = {0};
		queue<int> q;
		q.push(start);
		vis[start] = 1;
		int dist[5001] = {0};
		rep(i, 0, n)
		dist[i] = INT_MAX;
		dist[0] = 0;

		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto it : adj[x])
				if (!vis[it])
				{
					q.push(it);
					vis[it] = 1;
					dist[it] = dist[x] + 1;
				}
		}
		if (dist[endPos] == INT_MAX)
			return 0;
		return dist[endPos] + 1;
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		wordList.insert(wordList.begin(), beginWord);
		int n = wordList.size();
		list<int> adj[n + 1];
		int pre = 0, endPos = -1;

		for (int i = 0; i < n; i++)
		{
			if (wordList[i] == endWord)
			{
				endPos = i;
				pre = 1;
				break;
			}
		}
		if (pre == 1)
		{
			for (int i = 0; i < n; i++)
			{
				string x = wordList[i];

				for (int j = i + 1; j < n; j++)
				{
					string y = wordList[j];

					if (y.size() == x.size())
					{
						int f = 0, flag = 0;
						for (int k = 0; k < y.size(); k++)
						{
							if (x[k] != y[k])
							{
								if (f == 0)f = 1;
								else
								{
									flag = 1;
									break;
								}
							}
						}
						if (flag == 0)
						{
							adj[i].push_back(j);
							adj[j].push_back(i);
						}
					}
				}
			}

			int dist = bfs(adj, beginWord, endWord, n, endPos);
			return dist;
		}
		else return 0;
	}
};
