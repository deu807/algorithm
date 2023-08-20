#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321;

using namespace std;

typedef long long ll;
typedef struct {
	ll from, to, val;
}edge;

ll n, m, s, e, l, graph[300][300];
double ans = INF;
vector<edge> v;

void floydwarshall() {
	for (ll k = 1; k <= n; k++) {
		for (ll j = 1; j <= n; j++) {
			for (ll i = 1; i <= n; i++) {
				if (i == j) continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				graph[j][i] = min(graph[j][i], graph[j][k] + graph[k][i]);
			}
		}
	}
}

void input() {
	cin >> n >> m;

	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i == j) continue;
			graph[i][j] = INF;
		}
	}

	for (ll i = 0; i < m; i++) {
		cin >> s >> e >> l;
		graph[s][e] = graph[e][s] = min(graph[s][e], l);
		v.push_back({ s, e, l });
	}
}

void solve() {
	floydwarshall();
	
	for (ll start = 1; start <= n; start++) {
		double tmp = 0;
		for (ll i = 0; i < v.size(); i++) {
			tmp = max(tmp, (double)(graph[start][v[i].from] + graph[start][v[i].to] + v[i].val) / 2);
		}
		ans = min(tmp, ans);
	}

	

	cout << fixed;
	cout.precision(1);
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}