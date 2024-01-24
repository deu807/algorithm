#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, sum;
priority_queue<int, vector<int>, greater<int>> pq;

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }
}

void solution()
{
  int a = 0, b = 0;

  while (pq.size() != 1)
  {

    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();

    sum += a + b;
    pq.push(a + b);
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