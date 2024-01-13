#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, V;
int x, y;
int visit[1001] = {
    0,
};
vector<int> adj[10002]; // 인접리스트
vector<int> bfs;        // 방문한 순서
vector<int> dfs;
queue<int> q;

void DFS(int s)
{
  visit[s] = 1;
  dfs.push_back(s);
  for (int i = 0; i < adj[s].size(); i++)
  {
    if (visit[adj[s][i]] != 1)
      DFS(adj[s][i]);
  }
}

void BFS(int s)
{
  q.push(s);
  visit[s] = 1;

  while (!q.empty())
  {
    int tmp = q.front();

    q.pop();
    bfs.push_back(tmp);

    for (int i = 0; i < adj[tmp].size(); i++)
    {
      if (visit[adj[tmp][i]] != 1)
      {
        q.push(adj[tmp][i]);
        visit[adj[tmp][i]] = 1;
      }
    }
  }
}

void input()
{
  cin >> N >> M >> V;

  for (int i = 0; i < M; i++)
  {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    // 양방향 간선 처리
  }
}

void solution()
{

  for (int i = 1; i <= N; i++)
  {
    sort(adj[i].begin(), adj[i].end());
    // 벡터안의 원소 오름차순 정렬
  }

  DFS(V);

  memset(visit, 0, sizeof(visit));

  BFS(V);

  for (int i = 0; i < dfs.size(); i++)
  {
    cout << dfs[i] << " ";
  }
  cout << "\n";

  for (int i = 0; i < bfs.size(); i++)
  {
    cout << bfs[i] << " ";
  }
}

void solve()
{
  input();
  solution();
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}