#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000

int n, m, from, to, ans1, ans2;
int graph[101][101];

void floydwashall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}
}

void input() {
	cin >> n >> m;
	for (int j = 0; j < m; j++) {
		cin >> from >> to;
		graph[from][to]++;
		graph[to][from]++;
	}
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (i != j && graph[i][j] == 0) graph[i][j] = INF;
	}
}

void solve() {

	floydwashall();

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << graph[i][j] << ' ';
		}cout << '\n';
	}*/

	int mi = INF, ma = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int time_sum = 0;
			for (int k = 1; k <= n; k++) {
				time_sum += min(graph[i][k], graph[j][k]);
			}

			if (mi > time_sum) {
				mi = time_sum;
				ans1 = i;
				ans2 = j;
			}

		}
	}
	cout << ans1 << ' ' << ans2 << ' ' << mi * 2;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}