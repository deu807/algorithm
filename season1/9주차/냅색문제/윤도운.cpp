#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

vector<int> weight1, weight2;
vector<int> sum1, sum2;

int binarySearch(vector<int> &sum, int target)
{
  int left = 0, right = sum.size() - 1, mid, answer = -1;
  while (left <= right)
  {
    mid = (left + right) / 2;
    if (sum[mid] <= target)
    {
      answer = mid;
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return answer;
}

void dfs(int idx, int sum, vector<int> &weight, vector<int> &answer)
{

  // 재귀함수 탈출조건
  if (sum > C)
    return; // 이미 C라는 값보다 더 커졌을 경우 탐색할 필요가 없다.
  if (idx == weight.size())
  { // 모든 인덱스를 더했을 경우
    answer.push_back(sum);
    return;
  }

  // 1. 물건을 넣는 경우
  dfs(idx + 1, sum + weight[idx], weight, answer);
  //  물건을 넣는 것이므로 idx는 하나 증가, 물건을 담아준 것이므로 sum에다가 현재 무게 더해준다

  // 2. 물건을 안 넣는 경우
  dfs(idx + 1, sum, weight, answer);
  // 물건을 넣지 않았으므로 sum을 증가시키지 않는다
}

void input()
{
  // 1. 절반은 weight1 , 나머지 절반은 weight2 에 입력받기

  cin >> N >> C;

  for (int i = 0; i < N; i++)
  {
    int weight;
    cin >> weight;
    if (i < N / 2)
    {
      weight1.push_back(weight);
    }
    else
    {
      weight2.push_back(weight);
    }
  }
}

void solve()
{
  // 2. DFS로 sum1 , sum2 만들기

  dfs(0, 0, weight1, sum1); // ( index, sum, weight1, sum1 )
  dfs(0, 0, weight2, sum2); // ( index, sum, weight2, sum2 )
  // ex) 0번쨰 인덱스의 값을 weight에서 가져와서 완성된 sum이라는 값을 sum1에 담는다.

  // 3. 정렬 이후 이진 탐색

  sort(sum2.begin(), sum2.end());

  int answer = 0;
  for (int i = 0; i < sum1.size(); i++)
  {
    int searchValue = C - sum1[i];                 // 즉 C라는 최대값에서 현재의 값을 빼면 sum2에서 찾아야할 값이 저장됨
    answer += binarySearch(sum2, searchValue) + 1; // 인덱스 값을 반환, 경우의 수는 + 1
  }

  cout << answer << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}