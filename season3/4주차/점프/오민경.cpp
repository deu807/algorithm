#include <iostream>
using namespace std;

int N;
int map[100][100];
long long dp[100][100];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;
			int value = map[i][j];
			int down = value + i;
			int right = value + j;
			if (down < N) dp[down][j] += dp[i][j]; 
			if (right < N) dp[i][right] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1] << endl;

	return 0;
}