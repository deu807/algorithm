#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int A, B;
bool check[100001];
int ary[100001] = {0};
int sum;

void input()
{
  cin >> A >> B;
}

void solution()
{

  fill_n(check, 100002, 1);
  check[0] = 0;
  check[1] = 0;

  for (int i = 2; i < 100000l; i++)
  {
    if (check[i])
    {
      for (int j = i * 2; j <= B; j += i)
      {
        check[j] = 0;
        int tmp = j;
        while (tmp % i == 0)
        {
          tmp /= i;
          ary[j]++;
        }
      }
    }
  }

  for (int i = A; i <= B; i++)
  {
    if (check[ary[i]])
      sum++;
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