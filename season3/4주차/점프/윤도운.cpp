#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;
int ary[101][101] = {0};
long long dp[101][101] = {0};

void solution()
{

  dp[0][0] = 1;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {

      if (ary[i][j] == 0)
        continue;

      // 아래
      int x = i + ary[i][j];
      // 오른쪽
      int y = j + ary[i][j];

      if (x < N)
      {
        dp[x][j] += dp[i][j];
      }

      if (y < N)
      {
        dp[i][y] += dp[i][j];
      }
    }
  }

  cout << dp[N - 1][N - 1];
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> ary[i][j];
    }
  }

  solution();

  return 0;
}