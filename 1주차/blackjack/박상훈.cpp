#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[101], ans = 0;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	for (int i = 0; i < n - 2; i++)
		for (int j = i+1; j < n - 1; j++)
			for (int k = j+1; k < n; k++)
				if (arr[i] + arr[j] + arr[k] <= m) ans = max(ans, arr[i] + arr[j] + arr[k]);
	
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}