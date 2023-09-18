#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int n, m, arr[101][101], dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
bool visit[101][101];


void input() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
}

void solve() {
	q.push({ 0,0 });
	visit[0][0] = 1;
	int ans = 1;
	while (!q.empty()) {

		int cur_size = q.size();
		

		while (cur_size--) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
					if (!visit[ny][nx] && arr[ny][nx]) {
						visit[ny][nx] = 1;
						q.push({ ny,nx });
						if (ny == n - 1 && nx == m - 1) {
							cout << ++ans;
							return;
						}
					}
				}
			}
		}
		ans++;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}