class Solution {
public:
	double maxAverageRatio(vector<vector<int>>& v, int extraStudents)
	{
		int m = v.size();
		double sum = 0, ans = 0;

		priority_queue<pair<double, pair<int, int>>> p;

		for (int i = 0; i < m; i++)
		{
			double avg = (double)(v[i][0] + 1) / (v[i][1] + 1) - (double)(v[i][0]) / (v[i][1]);
			p.push({avg, {v[i][0], v[i][1]}});
		}

		for (int i = 0; i < extraStudents; i++)
		{
			auto temp = p.top();

			double val = temp.first;

			int x = temp.second.first;
			int y = temp.second.second;

			p.pop();

			x ++;
			y ++;

			val = (double)(x + 1) / (y + 1) - (double)(x) / (y);

			p.push({val, {x, y}});
		}
		while (!p.empty())
		{
			sum += (double)p.top().second.first / p.top().second.second;
			p.pop();
		}

		ans = sum / m;

		return ans;
	}
};
