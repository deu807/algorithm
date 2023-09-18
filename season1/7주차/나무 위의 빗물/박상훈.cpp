#include <iostream>
#include <vector>
using namespace std;

int n, w, from, to;
vector<int> v[500001];

void input() {
	cin >> n >> w;
	for (int i = 0; i < n - 1; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void solve() {
	int div = 0;
	for (int i = 2; i <= n; i++) {
		if (v[i].size() == 1) div++;
	}

	cout.precision(6);
	cout << fixed << (double)w / div;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}