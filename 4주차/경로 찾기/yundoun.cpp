#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  int N; // 정점의 개수

  cin >> N;

  int graph[101][101];

  for (int i = 0; i < N; i++)
  { // 그래프 입력받기
    for (int j = 0; j < N; j++)
    {
      cin >> graph[i][j];
    }
  }

  for (int k = 0; k < N; k++)
  { // 경유지
    for (int i = 0; i < N; i++)
    { // 시작 정점
      for (int j = 0; j < N; j++)
      { // 도착 정점
        if (graph[i][k] == 1 && graph[k][j] == 1)
          graph[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < N; i++)
  { // 그래프 출력
    for (int j = 0; j < N; j++)
    {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}