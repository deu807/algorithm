#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info {
	int from, to, cost;
} info;

int n, m, from, to, cost, ans, Max;
vector<info> ve;
int parent[100001];

int find(int x) {
	if(parent[x] == x) return x;
	
	return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	parent[a] = b;
}

bool comp(info a, info b) {
	return a.cost < b.cost;
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		ve.push_back({ from, to, cost });
	}
}

void solve() {
	sort(ve.begin(), ve.end(), comp);
	for (auto i : ve) {
		if (find(i.from) != find(i.to)) {
			Union(i.from, i.to);
			ans += i.cost;
			Max = max(Max, i.cost);
		}
	}
	cout << ans - Max;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}