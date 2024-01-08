#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, K;

void input()
{
  cin >> N >> K;

  queue<int> que;

  for (int i = 1; i <= N; i++)
  {
    que.push(i);
  }
  cout << "<";
  for (int i = 0; i < N; i++)
  {
    if (que.size() > 1)
    {
      for (int j = 0; j < K - 1; j++)
      {
        int front = que.front();
        que.pop();
        que.push(front);
      }
      cout << que.front() << ", ";
      que.pop();
    }
  }
  cout << que.front() << "> ";
}

void solution()
{
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