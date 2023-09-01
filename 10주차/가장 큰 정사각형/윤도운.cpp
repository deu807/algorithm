#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;
int DP[1001][1001];

void input()
{
  cin >> N >> M;
  long max = 0;

  for (int i = 0; i < N; i++)
  {
    string str;
    cin >> str;
    for (int j = 0; j < M; j++)
    {
      DP[i][j] = str[j] - '0'; // int 형 변환
      if (DP[i][j] == 1 && j > 0 && i > 0)
      { // 가장 자리 칸들 제외
        DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
        // 왼쪽, 왼쪽 대각선 위, 위 3가지 값 비교 이후, 자기 자신의 값 1 더해주기
      }
      if (max < DP[i][j])
      {
        max = DP[i][j]; // 최대값 계속해서 업데이트
      }
    }
  }

  cout << max * max << endl; // 넓이는 한 변의 제곱
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