#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[1001][1001];

string str1, str2;

void input() {
	cin >> str1 >> str2;
}

void solution() {
	int str1_size = str1.size();
	int str2_size = str2.size();

	for (int i = 1; i <= str1_size; i++) {
		for (int j = 1; j <= str2_size; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}

	cout << DP[str1_size][str2_size] << endl;
}

void solve() {
	input();
	solution();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;

}

