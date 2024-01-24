#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
int ary[51] = {0};
int cnt;

void input()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> ary[i];
  }
}

void solution()
{
  int tmp = 0;
  for (int i = 0; i < N; i++)
  {
    tmp += ary[i];
    if (tmp > M)
    {
      cnt++;
      tmp = ary[i];
    }
  }
  if (N == 0)
  {
    cout << 0;
  }
  else
  {
    cout << cnt + 1;
  }
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