#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	deque<int> d;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	while ((int)d.size() != 1) {
		d.pop_front();
		d.push_back(d.front());
		d.pop_front();
	}
	cout << d.front();
}