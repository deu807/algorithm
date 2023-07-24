#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, m, v1, v2, ans;
int parent[1000001];
map<int, bool> visit;

int find(int x) {
	if (parent[x] == x) return x;

	return parent[x] = find(parent[x]);
}

void Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;

	parent[u] = v;
}

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		if (find(v1) == find(v2)) {
			ans++;
		}
		else {
			Union(v1, v2);
		}
	}
}

void solve() {
	int cur = find(1);
	visit[cur] = 1;
	for (int i = 2; i <= n; i++) {
		cur = find(i);
		if (!visit[cur]) {
			visit[cur] = 1;
			ans++;
		}
		//cout << cur << '\n';
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	input();
	solve();
}