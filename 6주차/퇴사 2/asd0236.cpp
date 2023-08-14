#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cost, money, dp[1500001], ans;
vector<pair<int, int>> v;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost >> money;
		v.push_back({ cost, money });
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i]);
		int next = v[i - 1].first + i;
		if (next > n+1) continue;
		dp[next] = max(dp[next], dp[i] + v[i - 1].second);
		ans = max(dp[next], ans);
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}*/

	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}