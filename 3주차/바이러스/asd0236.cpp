#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<int> v[101];
queue<int> q;
bool visit[101];

void input() {
	cin >> n >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void solve() {
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (!visit[next]) {
				visit[next] = 1;
				q.push(next);
				ans++;
			}
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