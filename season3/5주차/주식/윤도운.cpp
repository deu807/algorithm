#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, N, M;
  long long ans;
  cin >> T;

  for (int i = 0; i < T; i++)
  {

    cin >> N;

    M = 0;
    ans = 0;
    vector<int> ary(N);

    for (int i = 0; i < N; i++)
    {
      cin >> ary[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
      M = max(M, ary[i]);
      ans += M - ary[i];
    }

    cout << ans << "\n";
  }

  return 0;
}