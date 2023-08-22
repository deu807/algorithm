#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool is_prime(int x) {
	if (x < 2) return 0;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

void dfs(int cur, int depth) {
	if (!is_prime(cur)) return;
	if (depth == n) {
		cout << cur << '\n';
		return;
	}

	dfs(cur * 10 + 1, depth + 1);
	dfs(cur * 10 + 3, depth + 1);
	dfs(cur * 10 + 7, depth + 1);
	dfs(cur * 10 + 9, depth + 1);

}

void input() {
	cin >> n;
}

void solve() {
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}