#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  int N;                 // 카드의 개수 입력받기
  int M;                 // 카드의 최대값
  vector<int> list(100); // 카드를 저장할 벡트
  int total = 0;         // 선택한 카드의 합
  int max = 0;
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  { // N개의 카드 만큼 입력받아 배열에 저장
    cin >> list[i];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        total = list[i] + list[j] + list[k];
        if (max <= total && M >= total)
          max = total;
      }
    }
  }

  cout << max;

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}