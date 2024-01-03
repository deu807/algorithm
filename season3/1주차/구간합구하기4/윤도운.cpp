#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
int a, b;

int S[100001] = {};

void input()
{

  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    int tmp;
    cin >> tmp;

    S[i] = S[i - 1] + tmp; // 합 배열 구하기
  }
}

void solution()
{

  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    cout << S[b] - S[a - 1] << "\n"; // 구간 합 구하기
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