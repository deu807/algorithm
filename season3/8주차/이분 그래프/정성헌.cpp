#include<bits/stdc++.h>
using namespace std;

int T,V,E,visited[20001];
vector<int>graph[20001];
void dfs(int cur)
{
	if (!visited[cur])
		visited[cur] = 1;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (!visited[next])
		{
			if (visited[cur] == 1)
			{
				visited[next] = 2;
				dfs(next);
			}
			else
			{
				visited[next] = 1;
				dfs(next);
			}
		}
	}
}
bool checkGraph()
{
	for (int i = 1; i <=V; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (visited[i] == visited[graph[i][j]])
				return false;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			int u = 0, v = 0;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= V; i++)
		{
			if (!visited[i])
				dfs(i);
		}
		if (checkGraph())
			cout << "YES"<<'\n';
		else
			cout << "NO"<<'\n';

		for (int i = 1; i <=V; i++)
		{
			graph[i].clear();
		}
		fill_n(visited, 20001, 0);
	}
}