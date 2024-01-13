#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N, ans;
string Number;
vector<string> v;
set<string> s;

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    string tmp;
    cin >> tmp;

    reverse(tmp.begin(), tmp.end());
    v.push_back(tmp);
  }
}

void solution()
{

  int size = 1;
  while (1)
  {
    for (int i = 0; i < N; i++)
    {
      s.insert(v[i].substr(0, size));
    }

    if (s.size() == N)
    {
      break;
    }
    else
    {
      size++;
      s.clear();
    }
  }

  ans = size;
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