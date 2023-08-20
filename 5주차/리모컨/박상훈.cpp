#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int n, m, val, ans = 987654321;
vector<int> v;

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> val;
		v.push_back(val);
	}
}

void solve() {
	for (int i = 0; i < max(100, n*2); i++) {
		string s = to_string(i);
		bool flag = 0;
		for (auto j : s) {
			for (auto k : v) {
				if (j - '0' == k) {
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) continue;
		//cout << i << '\n';
		ans = min(ans, abs(n - i) + (int)s.size());
	}
	//ans += (int)to_string(n).size();
	ans = min(ans, abs(n - 100));
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}