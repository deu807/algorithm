#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321;

int v, e, p, a, b, c;
vector<pair<int, int> > ve[5001];
priority_queue<pair<int, int> > pq;
int d[5001];

void dijkstra(int start) {
	for (int i = 1; i <= v; i++) d[i] = INF;
	d[start] = 0;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (d[cur] < cost) continue;
		
		for (auto i : ve[cur]) {
			int next = i.first;
			int next_cost = cost + i.second;
			if (next_cost < d[next]) {
				d[next] = next_cost;
				pq.push({ next, -next_cost });
			}
		}
	}
}

void input() {
	cin >> v >> e >> p;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		ve[a].push_back({ b,c });
		ve[b].push_back({ a,c });
	}
}

void solve(){
	dijkstra(1);
	int tmp1 = d[v], tmp2 = d[p];
	dijkstra(p);
	tmp2 += d[v];
	
	if (tmp1 == tmp2) cout << "SAVE HIM";
	else cout << "GOOD BYE";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}