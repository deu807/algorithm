#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

long long n, ans;
vector<int> v;


void input() {
	cin >> n;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}
}

void solve() {
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int s = v[i] + v[j];
			int l = lower_bound(v.begin() + j + 1, v.end(), s * -1) - v.begin();
			int u = upper_bound(v.begin() + j + 1, v.end(), s * -1) - v.begin();

			ans += u - l;
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}