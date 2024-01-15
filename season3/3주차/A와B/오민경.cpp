#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string S, T;
	cin >> S;
	cin >> T;
	for (int i = T.size() - 1; i >= 0; i--) {
		if (T[i] == 'A') { T.pop_back(); }
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
		if (S==T) { cout << "1"; return 0; }
	}
	cout << "0";

	return 0;
}