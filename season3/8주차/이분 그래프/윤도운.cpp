#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<bool> check;
vector<bool> visited;
bool IsEven = 1;

void DFS(int node)
{
  visited[node] = 1;

  for (int i : A[node])
  {
    if (!visited[i])
    {
      check[i] = !check[node];
      DFS(i);
    }
    else if (check[node] == check[i])
    {
      IsEven = false;
    }
  }
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int V, E;
    cin >> V >> E;
    A.resize(V + 1);
    visited.resize(V + 1);
    check.resize(V + 1);
    IsEven = 1;

    for (int j = 0; j < E; j++)
    {
      int S, E;
      cin >> S >> E;
      A[S].push_back(E);
      A[E].push_back(S);
    }

    // 모든 노드 탐색해야함 => 하나로 연결된다는 보장 없음
    for (int j = 1; j <= V; j++)
    {
      if (IsEven)
      {
        DFS(j);
      }
      else
      {
        break;
      }
    }
    if (IsEven)
    {
      cout << "YES"
           << "\n";
    }
    else
    {
      cout << "NO"
           << "\n";
    }
    for (int i = 0; i <= V; i++)
    {
      A[i].clear();
      visited[i] = false;
      check[i] = 0;
    }
  }
}