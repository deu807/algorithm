#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
int score[301];
int dp[301];

void input()
{
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    cin >> score[i];
  }
}

void solution()
{

  dp[0] = 0;
  score[0] = 0;

  dp[1] = score[1];
  dp[2] = score[1] + score[2];
  dp[3] = max(score[1] + score[3], score[2] + score[3]);

  for (int i = 4; i <= N; i++)
  {
    dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
  }

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