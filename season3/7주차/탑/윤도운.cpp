#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<pair<int, int>> st;

int n, x;

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> x;

    while (!st.empty())
    {
      if (x < st.top().second)
      { // 수신탑 찾음
        cout << st.top().first << " ";
        break;
      }

      st.pop(); // 찾을때까지 뽑기
    }
    if (st.empty())
    {
      cout << "0"
           << " ";
    }
    st.push(make_pair(i + 1, x));
  }

  return 0;
}