int minSteps(vector<int>&KnightPos, vector<int>&TargetPos, int N)
{
	queue of Pair(int, int) + int ;// for (x & y) + dist
	visited matrix;

	2 Arrays for dx and dy change in every move;
of the Knight - 8 possible moves;

while (queue not empty)
	{
		pop pair;

		if (destination reached)
			return dist_value;

		else
		{
			for (traverse all 8 moves in BFS way from array created)
			{
				if (isSafe(x, y) + vis[x][y] == 0)
				{
					Push to queue;
					mark visited;
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
#define ff first
#define ss second
public:
	bool isSafe(int x, int y, int N)
	{
		if (x >= 1 && x <= N && y >= 1 && y <= N)
			return true;
		return false;
	}
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
		// Code here
		int vis[N + 1][N + 1] = {0};
		queue<pair<pair<int, int>, int>> q;
		q.push({{KnightPos[0], KnightPos[1]}, 0});
		vis[KnightPos[0]][KnightPos[1]] = 1;

		int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2};
		int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1};

		while (!q.empty())
		{
			pair<pair<int, int>, int> temp = q.front();
			q.pop();

			if (temp.ff.ff == TargetPos[0] && temp.ff.ss == TargetPos[1])
			{
				return temp.ss;
			}
			for (int i = 0; i < 8; i++)
			{
				int x1 = temp.ff.ff + dx[i];
				int y1 = temp.ff.ss + dy[i];
				if (isSafe(x1, y1, N) && vis[x1][y1] == 0)
				{
					q.push({{x1, y1}, temp.ss + 1});
					vis[x1][y1] = 1;
				}
			}
		}
	}
};
