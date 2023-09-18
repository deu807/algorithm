#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, val;
vector<int> stack;
string cmd;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> cmd;
		if (cmd == "push") {
			cin >> val;
			stack.push_back(val);
		}
		else if (cmd == "pop") {
			if (stack.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << stack.back() << '\n';
			stack.pop_back();
		}
		else if (cmd == "size") {
			cout << stack.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << stack.empty() << '\n';
		}
		else { // cmd == "top"
			if (stack.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << stack.back() << '\n';
		}

	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	//solve();
}