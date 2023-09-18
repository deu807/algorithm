#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
vector<pair<int, int> > v[10001];
bool visit[10001];

void dfs(int cur, int depth) {
	for (auto i : v[cur]) {
		if (!visit[i.first]) {
			visit[i.first] = 1;
			dfs(i.first, depth + i.second);
			visit[i.first] = 0;
		}
	}
	ans = max(ans, depth);
}

void input() {
	int from, to, cost;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		if (v[i].size() == 1) {
			visit[i] = 1;
			dfs(i, 0);
			visit[i] = 0;
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