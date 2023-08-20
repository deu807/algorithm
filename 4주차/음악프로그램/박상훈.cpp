#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k, num, degree[1001];
vector<int> ans, graph[1001];
queue<int> q;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int prev = num;
			cin >> num;
			if (j)
			{
				degree[num]++;
				graph[prev].push_back(num);
			}
		}
	}
}

void solve()
{

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		ans.push_back(cur);

		for (auto i : graph[cur])
		{
			if (--degree[i] == 0)
				q.push(i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (degree[i])
		{
			cout << '0';
			return;
		}
	}

	for (auto i : ans)
		cout << i << '\n';
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}