//https://www.interviewbit.com/problems/valid-path/
bool isvalid(int x, int y, int X, int Y)
{
    if (x >= X || y >= Y || x < 0 || y < 0)
        return false;
    return true;
}
string Solution::solve(int X, int Y, int n, int r, vector<int> &E, vector<int> &F)
{
    bool vis[X][Y] = {0};
    queue<pair<int, int>> q;

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            for (int k = 0; k < E.size(); k++)
            {
                if (sqrt((pow((E[k] - 1 - i), 2) + pow((F[k] - 1 - j), 2))) <= r)
                {
                    vis[i][j] = -1;
                }
            }
        }
    }

    if (vis[0][0] == -1)
        return "NO";

    vis[0][0] = 1;
    q.push({0, 0});

    int dx[8] = {1, +1, +0, -1, -1, -1, 0, 1};
    int dy[8] = {0, -1, -1, -1, +0, +1, 1, 1};

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        int x = temp.first;
        int y = temp.second;
        q.pop();

        if (x == X - 1 && y == Y - 1)
            return "YES";

        for (int i = 0; i < 8; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (vis[newx][newy] == 0 && isvalid(newx, newy, X, Y))
            {
                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
    return "NO";
}
