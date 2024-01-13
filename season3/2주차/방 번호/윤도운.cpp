#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string N;
int ans = 1;
int ary[10] = {0};

void input()
{
  cin >> N;
}

void solution()
{

  for (int i = 0; i < N.size(); i++)
  {
    int idx = N[i] - '0';
    ary[idx]++;
  }

  for (int i = 0; i < 10; i++)
  {
    if (i != 6 && i != 9)
      ans = max(ans, ary[i]);
  }
  ans = max(ans, (ary[6] + ary[9] + 1) / 2);

  cout << ans;
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