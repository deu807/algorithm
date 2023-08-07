#include <iostream>
#include <vector>
using namespace std;

int n, m, parent[201];
vector<int> v;

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	parent[a] = b;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

void input() {
	int val;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> val;
			if (val) {
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> val;
		v.push_back(val);
	}
}

void solve() {
	for (int i = 1; i < v.size(); i++) {
		int prev = v[i - 1], cur = v[i];
		//cout << find(prev) << ' ' << find(cur) << '\n';
		if (find(prev) != find(cur)) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	init();
	input();
	solve();
}