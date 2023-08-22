#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int n, k, val, dp[10001];
vector<int> cost;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> val;
		cost.push_back(val);
	}
}

void solve() {

	//for (int i = 1; i <= k; i++) dp[i] = INF;
	sort(cost.begin(), cost.end());

	dp[0] = 1;

	for (int j = 0; j < n; j++) {
		for (int i = cost[j]; i <= k; i++) {
			dp[i] += dp[i-cost[j]];
		}
	}

	
	cout << dp[k];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}