class Solution {
public:
	//BellMan Ford Algo - DP Solution
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
	{
		/* distance from source to all other nodes */
		vector<int> dist( n, INT_MAX );
		dist[src] = 0;

		// Run only K+1 times since we want shortest distance in K hops
		for ( int i = 0; i <= K; i++ )
		{
			vector<int> tmp( dist );
			for ( auto flight : flights )
			{
				if ( dist[ flight[0] ] != INT_MAX )
				{
					tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
				}
			}
			dist = tmp;
		}
		return dist[dst] == INT_MAX ? -1 : dist[dst];
	}

/**************************************************************************************************/
/**************************************************************************************************/

	//Simple BFS - but gives TLE
	int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k)
	{

		//1. Create an Adjacency List
		vector<vector<vector<int>>> adjList(n);

		for (auto f : flights)
		{
			int from = f[0];
			int to = f[1];
			int cost = f[2];
			adjList[from].push_back({to, cost});
		}

		//2. Create a queue for performing BFS
		queue<vector<int>> q;

		//3. Push source in q as {src, money spent so far, number of stops b/w current city and source}
		q.push({src, 0, -1});
		//Note : if {A, B} are two directly connected cities, then number of stops b/w them is Zero,
		//so for convenience i'm assuming number of stops b/w A and A as -1

		int minCost = INT_MAX;   //this keeps track of minimum cost


		while (!q.empty())
		{
			vector<int> curStation = q.front();
			q.pop();

			int curCity = curStation[0];
			int curCost = curStation[1];
			int curK = curStation[2];      //this is the number of stops seen so far from source to current city

			if (curCity == dst)
			{
				minCost = min(minCost, curCost);
				continue;
			}


			for (auto p : adjList[curCity])
			{
				//we include a city in our route only if :
				// > it doesn't exceed number of stops alloted
				// > it keeps cost less than mincost
				//***
				if (curK + 1 <= k and curCost + p[1] < minCost)
					q.push({p[0], p[1] + curCost, curK + 1});
			}
		}
		return minCost == INT_MAX ? -1 : minCost;
	}

/**************************************************************************************************/
/**************************************************************************************************/

	//Simple DFS with Pruning - Gives TLE too
	int findCheapestPrice3(int n, vector<vector<int>>& flights, int s, int d, int K)
	{
		unordered_map<int, vector<pair<int, int>>> g;
		for (const auto& e : flights)
			g[e[0]].emplace_back(e[1], e[2]);
		int ans = INT_MAX;
		vector<int> visited(n, 0);
		dfs(s, d, K + 1, 0, visited, ans, g);
		return ans == INT_MAX ? - 1 : ans;
	}

	void dfs(int s, int d, int k, int cost, vector<int>& visited, int& ans, unordered_map<int, vector<pair<int, int>>>& g )
	{
		if (s == d)
		{
			ans = cost;
			return;
		}
		if (k == 0)
			return;
		visited[s] = 1;
		for (const auto& x : g[s])
		{
			if (visited[x.first] == 0)
			{
				if (cost + x.second > ans) continue; // IMPORTANT!!! prunning

				dfs(x.first, d, k - 1, cost + x.second, visited, ans, g);
			}
		}
		visited[s] = 0;
	}
};
