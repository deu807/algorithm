#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans = 0;
vector<pair<int, int> > arr;

bool comp(pair<int, int> x, pair<int, int> y) {
	if (x.second == y.second) return x.first < y.first;
	return x.second < y.second;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
}

void solve() {
	sort(arr.begin(), arr.end(), comp);

	int cur = 0;
	for (auto i : arr) {
		if (cur <= i.first) {
			cur = i.second;
			ans++;
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