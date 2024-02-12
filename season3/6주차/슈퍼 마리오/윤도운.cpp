#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int v[10];
int sum;

void input()
{
  for (int i = 0; i < 10; i++)
  {
    cin >> v[i];
  }
}

void solution()
{

  for (int i = 0; i < 10; i++)
  {

    if (abs(100 - sum) >= abs(100 - (sum + v[i])))
    {
      sum += v[i];
    }
    else
      break;
  }

  cout << sum;
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