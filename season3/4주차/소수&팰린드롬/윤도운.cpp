#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int N;

void input()
{
  cin >> N;
}

bool prime(int n)
{
  if (n < 2)
    return 0;

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return 0;
  }

  return 1;
}

bool checkP(string n)
{
  string a, b;
  a = n;
  reverse(n.begin(), n.end());
  b = n;

  if (a == b)
    return 1;
  else
    return 0;
}

void solution()
{

  for (int i = N;; i++)
  {
    if (prime(i) && checkP(to_string(i)))
    {
      cout << i;
      break;
    }
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