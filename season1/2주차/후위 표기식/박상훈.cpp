#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

string s;
stack<char> st;

int Rank(char c) {
	switch (c) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '(': case ')': return 0;
	}
	return -1;
}

void input() {
	cin >> s;
}

void solve() {
	for (auto i : s) {
		if (i >= 'A' && i <= 'Z') cout << i;
		else if (i == '(') st.push(i);
		else if (i == ')') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			if (st.top() == '(') st.pop();
		}
		else {
			while (!st.empty()) {
				if (Rank(i) <= Rank(st.top())) {
					cout << st.top();
					st.pop();
				}
				else break;
			}
			st.push(i);
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	solve();
}