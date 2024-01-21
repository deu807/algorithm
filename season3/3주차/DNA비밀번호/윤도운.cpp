#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int S, P, ans = 0;
string DNA;

vector<int> ary(1000000, 0);
vector<int> ACGT(1000000, 0);

int start_idx, end_idx;

void input()
{
  cin >> S >> P;
  cin >> DNA;

  cin >> ary['A'];
  cin >> ary['C'];
  cin >> ary['G'];
  cin >> ary['T'];
}

void solution()
{
  start_idx = 0;
  end_idx = start_idx + P - 1;

  for (int i = start_idx; i <= end_idx; i++)
  {
    ACGT[DNA[i]]++;
  }

  while (end_idx < DNA.size())
  {
    if (ary['A'] <= ACGT['A'] && ary['C'] <= ACGT['C'] &&
        ary['G'] <= ACGT['G'] && ary['T'] <= ACGT['T'])
    {
      ans++;
    }
    ACGT[DNA[start_idx++]]--;
    ACGT[DNA[++end_idx]]++;
  }
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