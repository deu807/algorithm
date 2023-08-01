#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
private:
public:
  long long x;
  long long y;
};

Point p1, p2, p3, p4;

int answer;

int CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
  long long ccw = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

  if (ccw > 0)
    return 1; // 반시계 방향
  else if (ccw < 0)
    return -1; // 시계 방향
  else
    return 0; // 일직선 위
}

void input()
{
  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  cin >> p3.x >> p3.y >> p4.x >> p4.y;
}

void solution()
{

  // (p1, p2, p3) * (p1, p2, p4)
  long long a = CCW(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y) * CCW(p1.x, p1.y, p2.x, p2.y, p4.x, p4.y);
  // (p3, p4, p1) * (p3, p4, p2)
  long long b = CCW(p3.x, p3.y, p4.x, p4.y, p1.x, p1.y) * CCW(p3.x, p3.y, p4.x, p4.y, p2.x, p2.y);

  if (a == -1 && b == -1)
    answer = 1;
  else
    answer = 0;
}

void solve()
{
  input();
  solution();
  cout << answer << endl;
}

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}