#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// 가장 거리가 긴 간선을 dfs 탐색을 통해 구하여야 한다.

struct Node
{
  int index; // 인덱스
  int dist;  // 거리
};

int maxDist, maxNode;
bool visit[100001]; // 방문을 확인하기 위한 배열
vector<Node> graph[100001];

void dfs(int node, int dist)
{
  if (visit[node] == true)
    return;
  // 방문한 노드였을 경우 리턴

  if (maxDist < dist)
  {
    maxDist = dist;
    maxNode = node;
  }
  // 최대 거리 갱신

  visit[node] = true;
  // 방문햇음 체크하기

  for (int i = 0; i < graph[node].size(); i++)
  {
    int nextIndex = graph[node][i].index;
    int nextDist = graph[node][i].dist;
    dfs(nextIndex, nextDist + dist);
  }
  // 인접 정점들의 거리 탐색
}

void input()
{
  int n, a, b, c;

  cin >> n;

  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
}

void solve()
{
  input();
  dfs(1, 0); // 가장 멀리 있는 점 구하기

  maxDist = 0;
  // 1과 가장 먼 정점에서 다시 dfs 수행하여 트리의 지름 찾기

  memset(visit, 0, sizeof(visit));
  // 특정 메모리 영역을 원하는 값으로 초기화 => visit 배열을 초기화 하기 위해서

  dfs(maxNode, 0);
  cout << maxDist << '\n';
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}