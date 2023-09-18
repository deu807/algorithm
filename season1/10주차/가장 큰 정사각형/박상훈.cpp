#include <iostream>
#include <algorithm>
using namespace std;

int n, m, dp[1001][1001], ans = 0;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			dp[i][j] = str[j] - '0';
			ans = max(ans, dp[i][j]);
		}
	}
}

void solve() {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j]) {
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}


	cout << ans * ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}