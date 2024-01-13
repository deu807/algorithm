#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long S, N;

void input()
{
  cin >> S;
  long long sum = 0;
  int cnt = 1;
  while (S >= sum)
  {
    sum += cnt;
    cnt++;
  }
  cout << cnt - 2;
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