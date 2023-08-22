#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using	namespace std;

int t;		// 테스트 케이스
int n;		// 전화번호의 수




void input() {
	cin >> t;
}

void solution() {

	for (int i = 1; i <= t; i++) {
		cin >> n;
		string str;

		vector<string> vecNum;
		for (int j = 0; j < n; j++) {
			cin >> str;
			vecNum.push_back(str);
		}


		sort(vecNum.begin(), vecNum.end()); // 벡터 정렬
		bool flag = true;

		for (int i = 0; i < vecNum.size() - 1; i++) {

			string cur = vecNum[i]; // 현재 문자열의 길이
			string next = vecNum[i + 1]; // 다음 문자열의 길이


			flag = true;
			if (cur.length() > next.length()) continue;
			// 현재 문자열의 길이 > 다음 문자열의 길이 => 접두어가 될 수 없으므로 생략
			if (cur == next.substr(0, cur.length())) {
				flag = false;
				break;
			}
		}
		if (!flag) cout << "NO" << endl;
		else cout << "YES" << endl;

	}
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