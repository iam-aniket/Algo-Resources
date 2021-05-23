//https://www.youtube.com/watch?v=5h1JYjin_4o
//Code Library YT
vector<int> inTime;
vector<int> outTime;
int timer = 1;

void resize(int n)
{
	inTime.resize(n + 1);
	outTime.resize(n + 1);
}

void dfs(int src, int par, vector<int> g[])
{
	inTime[src] = timer++;
	for (auto x : g[src]) {
		if (x != par) {
			dfs(x, src, g);
		}
	}
	outTime[src] = timer++;
}

bool check(int x, int y)
{
	if (inTime[x] > inTime[y] and outTime[x] < outTime[y])
		return true;
	return false;
}
