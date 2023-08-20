#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int entry[1001];
vector<int> v[1001];

// 가장 먼저 무대를 오를 수 있는 사람은 entry 값이 0인 사람
// 앞에 사람이 무대를 했다면 이후 무대를 할 가능성이 있는 사람의
// 엔트리 값을 하나씩 빼주면 된다.

void input()
{
  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    vector<int> tmp;
    int x;
    cin >> x;
    for (int j = 0; j < x; j++)
    {
      int t;
      cin >> t;
      tmp.push_back(t);
    }
    for (int j = 0; j < tmp.size(); j++)
    {
      for (int k = j + 1; k < tmp.size(); k++)
      {
        v[tmp[j]].push_back(tmp[k]);
        entry[tmp[k]]++;
      }
    }
  }
}

void solution()
{
  queue<int> q;

  for (int i = 1; i <= N; i++)
  {
    if (entry[i] == 0)
      q.push(i);
  }

  vector<int> answer;
  while (q.empty() == 0)
  {
    int n = q.front();
    q.pop();
    answer.push_back(n);

    for (int i = 0; i < v[n].size(); i++)
    {
      int next = v[n][i];
      entry[next]--;

      if (entry[next] == 0)
        q.push(next);
    }
  }
  if (answer.size() != N)
    cout << 0 << endl;
  else
  {
    for (int i = 0; i < answer.size(); i++)
      cout << answer[i] << endl;
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