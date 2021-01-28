void dfs(int x,int y,int m[][MAX],int visited[][MAX],vector<string>& ans,string& temp)
{
	if(/*( Invalid access )*/ )
	return;

	if(/*( Base Condition - Target pos reached)*/ )
	{
		ans.pb(temp); //Insert to ans
		return;//VVI		
	}

	visited[x][y] = 1;
	
	if(isSafe(x+1,y,...))
	{
		temp.pb('D');
		rat(x+1,y,...);//Recurr depth first search way
		temp.pop_back();
	}

	if(isSafe(x-1,y...))
	{ ... }

	if(isSafe(x,y+1...))
	{ ... }

	if(isSafe(x,y-1...))
	{ ... }
	
	visited[x][y] = 0;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*            Remember return is VVI after reaching end - since DFS                                      */


bool isSafe(int row, int col, int m[][MAX], int n, bool visited[][MAX])
{
	if (row == -1 || row == n || col == -1 || col == n || visited[row][col]
	        || m[row][col] == 0)
		return false;

	return true;
}

void rat(int x, int y, int m[][MAX], int n, string &temp, vector<string> &ans, bool visited[][MAX])
{
	if (x == -1 || y == -1 || x == n || y == n || visited[x][y] || m[x][y] == 0)
		return;
	if (x == n - 1 && y == n - 1)
	{
		ans.pb(temp);
		return;
	}

	visited[x][y] = 1;

	if (isSafe(x + 1, y, m, n, visited))
	{
		temp.pb('D');
		rat(x + 1, y, m, n, temp, ans, visited);
		temp.pop_back();
	}

	if (isSafe(x, y - 1, m, n, visited))
	{
		temp.pb('L');
		rat(x, y - 1, m, n, temp, ans, visited);
		temp.pop_back();
	}
	if (isSafe(x, y + 1, m, n, visited))
	{
		temp.pb('R');
		rat(x, y + 1, m, n, temp, ans, visited);
		temp.pop_back();
	}
	if (isSafe(x - 1, y, m, n, visited))
	{
		temp.pb('U');
		rat(x - 1, y, m, n, temp, ans, visited);
		temp.pop_back();
	}

	visited[x][y] = 0;

}
vector<string> findPath(int m[MAX][MAX], int n)
{
	string temp;
	vector<string> ans;
	bool visited[MAX][MAX];
	rep(i, 0, MAX)
	rep(j, 0, MAX)
	visited[i][j] = 0;
	rat(0, 0, m, n, temp, ans, visited);
	return ans;
}
