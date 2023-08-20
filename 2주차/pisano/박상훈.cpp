#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, tc, n, fibo[1000001];

void init() {
	fibo[1] = 1;
	fibo[2] = 1;
}

void input() {
	cin >> t;
	while (t--) {
		cin >> tc >> n;
		cout << tc << ' ';
		
		for (int i = 3;; i++) {
			fibo[i] = (fibo[i - 1] + fibo[i - 2]) % n;
			if (fibo[i] % n == 1 && fibo[i - 1] % n == 0) {
				cout << i-1 << '\n';
				break;
			}
		}

	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	init();
	input();
}