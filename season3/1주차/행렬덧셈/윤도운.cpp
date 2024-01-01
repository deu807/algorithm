#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, m;
int ary1[100][100];
int ary2[100][100];

void input()
{
  cin >> n;
  cin >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> ary1[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> ary2[i][j];
    }
  }
}

void solution()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ary1[i][j] + ary2[i][j] << " ";
    }
    cout << endl;
  }
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