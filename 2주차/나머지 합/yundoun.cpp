#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, x;

long long ary[1001];
long long sum, answer;

// (pSum[j] - pSum[i]) % Mod = 0인 구간을 구해야한다.
// pSum[j] % Mod = pSum[i] % Mod로 변환할 수 있다.

void input()
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> x;
    sum += x;       // 각 배열의 합을 구한다.
    ary[sum % M]++; // 각 배열의 합에서 나머지를 구한다.
  }
}

void solution()
{
  for (int i = 0; i <= 1000; i++)
  {
    answer += ary[i] * (ary[i] - 1) / 2; // 조합 공식 nC2
  }

  cout << ary[0] + answer; // (prefix_sum% MOD = 0인 개수)
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