#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, val;
vector<int> queue;
string cmd;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> cmd;
		if (cmd == "push") {
			cin >> val;
			queue.push_back(val);
		}
		else if (cmd == "pop") {
			if (queue.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << queue.front() << '\n';
			queue.erase(queue.begin());
		}
		else if (cmd == "size") {
			cout << queue.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << queue.empty() << '\n';
		}
		else if (cmd == "front") {
			if (queue.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << queue.front() << '\n';
		}
		else { // cmd == "back"
			if (queue.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << queue.back() << '\n';
		}

	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	input();
	//solve();
}