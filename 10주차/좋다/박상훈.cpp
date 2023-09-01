#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, ans;
vector<int> v;
map<int, int> ma;

void input() {
	int val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
		ma[val]++;
	}
}

void solve() {
	sort(v.begin(), v.end());

	
	for (int i = 0; i < n; i++) {
		int left = 0, right = n - 1;
		while (left < right) {
			//cout << left << ' ' << right << '\n';
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			int sum = v[left] + v[right];
			if (sum < v[i]) {
				left++;
			}
			else if (sum > v[i]) {
				right--;
			}
			else {
				ans++;
				break;
			}

		}
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}