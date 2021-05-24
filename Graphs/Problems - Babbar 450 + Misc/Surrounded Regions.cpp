//https://leetcode.com/problems/surrounded-regions/submissions/
/*
First, check the four border of the matrix. If there is a element is
'O', alter it and all its neighbor 'O' elements to '#'.

Then , alter all the 'O' to 'X'

At last, alter all the '1' to 'O'

For example:

X X X X           X X X X             X X X X
X X O X  ->       X X O X    ->       X X X X
X O X X           X # X X             X O X X
X O X X           X # X X             X O X X
*/

class Solution {
public:
	void bfs(vector<vector<char>> &board, int i, int j)
	{
		int m = board.size();
		int n = board[0].size();
		queue<pair<int, int> > q;
		q.push(make_pair(i, j));
		while (!q.empty())
		{
			pair<int, int> elem = q.front();
			q.pop();
			i = elem.first;
			j = elem.second;
			if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
			{
				board[i][j] = '#';
				q.push(make_pair(i - 1, j));
				q.push(make_pair(i + 1, j));
				q.push(make_pair(i, j - 1));
				q.push(make_pair(i, j + 1));
			}
		}
	}
	void solve(vector<vector<char>>& board)
	{
		int width = board.size();
		if (width == 0) //Add this to prevent run-time error!
			return;
		int length = board[0].size();
		if  (length == 0) // Add this to prevent run-time error!
			return;

		for (int i = 0; i < length; ++i)
		{
			if (board[0][i] == 'O')
				bfs(board, 0, i);

			if (board[width - 1][i] == 'O')
				bfs(board, width - 1, i);
		}

		for (int i = 0; i < width; ++i)
		{
			if (board[i][0] == 'O')
				bfs(board, i, 0);
			if (board[i][length - 1] == 'O')
				bfs(board, i, length - 1);
		}

		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < length; ++j)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '#')
					board[i][j] = 'O';
			}
		}
	}
};
