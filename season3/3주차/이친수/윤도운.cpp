#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
long long dp[92];
int ans;

void input()
{
  cin >> N;
}

void solution()
{

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;

  for (int i = 4; i <= N; i++)
  {
    dp[i] = dp[i - 2] + dp[i - 1];
  }

  if (N == 1)
    cout << 1;
  else if (N == 2)
    cout << 1;
  else if (N == 3)
    cout << 2;
  else
    cout << dp[N];
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