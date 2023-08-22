#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
string str;
map<string, int> m1;
map<int, string> m2;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		m1[str] = i;
		m2[i] = str;
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (str[0] >= 'A' && str[0] <= 'Z') cout << m1[str] << '\n';
		else cout << m2[stoi(str)] << '\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
}