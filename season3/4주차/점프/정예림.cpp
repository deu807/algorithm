#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int n;
int arr[101][101];
long long dp[101][101];
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 0인 좌표 건너뛰기
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;

			int move = arr[i][j];
			int right = j + move;		//오른쪽으로 이동
			int down = i + move;		//아래로 이동

			// 배열의 범위를 넘지 않을 때 이동
			if (right < n) dp[i][right] += dp[i][j];
			if (down < n) dp[down][j] += dp[i][j];
		}
	}
	
	cout << dp[n - 1][n - 1];

	return 0;
}