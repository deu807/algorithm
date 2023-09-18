#include <iostream>
#include <algorithm>
using namespace std;

int n, b, w, ans;
string s;

void input() {
	cin >> n >> b >> w;
	cin >> s;
}

void solve() {
	int left = 0, right = 0, black = 0, white = 0;
	while (right < n) {
		//cout << left << ' ' << right << '\n';
		if (s[right] == 'W') {
			white++;
			right++;
		}

		else {
			black++;
			right++;
			while (black > b && left < right) {
				
				switch (s[left++]) {
				case 'B':
					black--;
					break;
				case 'W':
					white--;
				}

			}
		}

		if (black <= b && white >= w) ans = max(ans, right - left);
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}