#include <iostream>
using namespace std;

int n, ans1, ans2;
bool arr[129][129];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void sol(int ystart, int xstart, int Size) {
	bool opt = arr[ystart][xstart];
	for (int i = ystart; i < ystart+Size; i++) {
		for (int j = xstart; j < xstart+Size; j++) {

			if (arr[i][j] != opt) {
				sol(ystart, xstart, Size / 2);
				sol(ystart, xstart + Size / 2, Size / 2);
				sol(ystart + Size / 2, xstart, Size / 2);
				sol(ystart + Size / 2, xstart + Size / 2, Size / 2);
				return;
			}

		}
	}

	if (opt)ans2++;
	else ans1++;
}

void solve() {
	sol(0, 0, n);
	cout << ans1 << '\n' << ans2;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}