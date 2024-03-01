#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, ans = 1;

vector<pair<int, int>> v;

priority_queue<int, vector<int>, greater<int>> q;

void input()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int start, end;
    cin >> start >> end;
    v.push_back({start, end});
  }
}

void solution()
{
  sort(v.begin(), v.end());
  q.push(v[0].second); // 종료시간을 우선순위로 큐에 삽입
  for (int i = 1; i < N; i++)
  {
    while (!q.empty() && q.top() <= v[i].first)
    { // 종료시간이 시작시간보다 작으면 끝난거임
      q.pop();
    }
    q.push(v[i].second); // 아닐경우 회의실 추가
    ans = max(ans, int(q.size()));
  }
  cout << ans;
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();

  return 0;
}