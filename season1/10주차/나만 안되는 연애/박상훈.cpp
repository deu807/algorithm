#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, u, v, d, ans;

typedef struct path {
	int cost, from, to;
}path;

bool se[1001];
vector<path> ve;
int parent[1001];

bool comp(path a, path b) {
	if (a.cost == b.cost) {
		if (a.to == b.to) {
			return a.from < b.from;
		}
		return a.to < b.to;
	}
	return a.cost < b.cost;
}

int find(int x) {
	if (x == parent[x]) return x;
	
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;

	parent[x] = y;
}

void input() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		char c;
		cin >> c;
		se[i] = c == 'M' ? 1 : 0;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> d;
		if (se[u] != se[v]) ve.push_back({ d, u, v });
	}
}

void solve() {
	sort(ve.begin(), ve.end(), comp);
	for (auto i : ve) {
		int from = i.from, to = i.to, cost = i.cost;


		if (find(from) == find(to)) continue;
		//cout << from << to << ' ' << cost << '\n';
		Union(from, to);
		ans += cost;
	}

	int check = find(1);
	for (int i = 2; i <= n; i++) {
		//cout << find(i) << '\n';
		if (find(i) != check) {
			cout << "-1";
			exit(0);
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