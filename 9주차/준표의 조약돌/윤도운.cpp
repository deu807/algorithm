#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, B, W;
int answer;
string str;

void input()
{
  cin >> N >> B >> W;
  cin >> str;
}

void solution()
{
  int left = 0, right = 0;
  int cnt_B = 0, cnt_W = 0;

  while (right < N)
  {

    // 1. 하얀돌 주웠을 경우
    if (str[right] == 'W')
    {
      cnt_W++;
      right++;
    }

    // 2. 검은돌 주웠을 경우
    else
    {
      cnt_B++;
      right++;
      // 2-1. 검은돌의 최대 갯수보다 더 많이 주웠을 경우
      while (cnt_B > B && left < right)
      {
        if (str[left] == 'B')
        {
          cnt_B--;
        }
        else if (str[left] == 'W')
        {
          cnt_W--;
        }
        left++;
      }
    }

    if (cnt_B <= B && W <= cnt_W)
      answer = max(answer, right - left);
  }
}

void solve()
{
  input();
  solution();
  cout << answer << '\n';
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}