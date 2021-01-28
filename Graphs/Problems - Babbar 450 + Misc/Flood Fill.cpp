class Solution
{
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
	{
		int n = image.size();
		int m = image[0].size();

		int vis[n + 1][m + 1];
		for (int i = 0; i < n ; i++)
			for (int j = 0; j < m; j++)
				vis[i][j] = 0;
		vis[sr][sc] = 1;
        
		queue<pair<int, int>> q;
		q.push(make_pair(sr, sc));
		int cur = image[sr][sc];
        
        int dx[] = { +1, -1, +0, +0};
	    int dy[] = { +0, +0, +1, -1};
        
		while (!q.empty())
		{
			pair<int, int> temp = q.front();
			q.pop();
			image[temp.first][temp.second] = newColor;

			for (int i = 0; i < 4; i++)
			{
				int x1 = temp.first + dx[i];
				int y1 = temp.second + dy[i];

				if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && image[x1][y1] == cur && vis[x1][y1] == 0)
				{
					vis[x1][y1] = 1;
					q.push(make_pair(x1, y1));
				}
			}
		}
		return image;
	}
};
