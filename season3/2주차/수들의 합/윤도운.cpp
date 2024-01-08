#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long S, N;

void input()
{
  cin >> S;
  long long tmp = 0;
  int cnt = 1;
  while (1)
  {

    tmp += cnt;
    if (tmp > S)
    {
      cout << cnt - 1;
      break;
    }
    cnt++;
  }
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