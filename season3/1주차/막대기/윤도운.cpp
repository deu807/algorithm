#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int v[100001];

int n, tmp;
int cnt = 0, MAX = 0;

void input()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
}

void solution()
{

  for (int i = n - 1; i >= 0; i--)
  {
    if (MAX < v[i])
    {
      cnt++;
      MAX = v[i];
    }
  }

  cout << cnt;
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