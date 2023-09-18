#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1000001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2]);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3]);

		dp[i]++;
	}
	cout << dp[n];
}