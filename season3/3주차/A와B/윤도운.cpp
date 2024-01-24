#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string S, T;

void input()
{
  cin >> S;
  cin >> T;
}

void solution()
{
  for (int i = 0; i < 1000; i++)
  {

    if (T.size() == S.size())
    {
      break;
    }

    else if (T.back() == 'A')
    {
      T.pop_back();
    }
    else
    {
      T.pop_back();
      reverse(T.begin(), T.end());
    }
  }

  if (S == T)
    cout << "1";
  else
    cout << "0";
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