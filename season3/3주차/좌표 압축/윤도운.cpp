#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> ans;

void input()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
    ans.push_back(tmp);
  }
}

void solution()
{
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 중복 제거

  for (int i = 0; i < N; i++)
  {
    cout << lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin() << " ";
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