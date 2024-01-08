#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M, cnt;

vector<string> v(10001);
vector<string> answer;

void input()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> v[i];
}

void solution()
{
  sort(v.begin(), v.end()); // 이진 탐색을 하기 위한 정렬

  for (int i = 0; i < M; i++)
  {
    string tmp;
    cin >> tmp;

    if (binary_search(v.begin(), v.end(), tmp))
      cnt++;
  }

  cout << cnt;
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