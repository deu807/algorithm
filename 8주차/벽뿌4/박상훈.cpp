#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m, dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 }, ans[1001][1001], ans2[1001][1001];
pair<int, int> parent[1001][1001];
string arr[1001];
queue<pair<int, int> > q;
bool visit[1001][1001];

pair<int, int> find(pair<int, int> x) {
	if (parent[x.first][x.second] == x) return x;

	return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void Union(pair<int, int> x, pair<int, int> y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	parent[x.first][x.second] = y;
}

void bfs() {
	int mark = 0;
	vector < pair<int, int> > list;
	pair<int, int> start = { q.front().first, q.front().second };
	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		list.push_back({ cury,curx });
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];
			
			if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if (!visit[ny][nx] && arr[ny][nx] == '0') {
					visit[ny][nx] = 1;
					q.push({ ny,nx });
					Union({ cury, curx }, { ny,nx });
				}
			}
		}
		mark++;
	}

	for (auto i : list) {
		ans[i.first][i.second] = mark;
	}
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			parent[i][j] = { i,j };
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] || arr[i][j] == '1') continue;
			q.push({ i,j });
			visit[i][j] = 1;
			bfs();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == 0) {

				int cury = i, curx = j;
				map<pair<int, int>, bool> ma;
				ma[find({ cury, curx })] = 1;
				for (int k = 0; k < 4; k++) {
					int ny = cury + dy[k], nx = curx + dx[k];
					if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
						if (ans[ny][nx] && ma[find({ny,nx})] == 0) {
							ans2[cury][curx] += ans[ny][nx];
							ma[find({ny, nx})] = 1;
						}
					}
				}
				ans2[i][j]++;

			}
		}
	}

	// output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans2[i][j]%10;
		}cout << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}