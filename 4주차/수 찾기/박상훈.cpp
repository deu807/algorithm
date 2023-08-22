#include <iostream>
#include <map>

using namespace std;

map<int, bool> m;

int n;

void input() {
	cin >> n;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		m[val] = 1;
	}
}

void solve() {
	cin >> n;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		cout << m[val] << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}