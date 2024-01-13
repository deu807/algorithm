#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
int cnt = 0, sum = 1;
int startIdx = 1, endIdx = 1;

void input()
{
  cin >> N;
}

void solution()
{
  while (endIdx != N)
  {
    if (N == sum)
    {
      cnt++;
      sum += ++endIdx;
    }
    else if (N < sum)
    {
      sum -= startIdx++;
    }
    else
    {
      sum += ++endIdx;
    }
  }

  cout << cnt + 1;
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