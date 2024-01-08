#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string number;
	vector<string> student;
	set<string> cut;
	cin >> N;
	int j = 1;
	for(int i=0; i<N; i++) {
		cin >> number;
		reverse(number.begin(), number.end());
		student.push_back(number);
	}
	while (1) {
		for (int i = 0; i < student.size(); i++) {
			cut.insert(student[i].substr(0, j));
		}
		if (cut.size() == N) break;
		else {
			j++;
			cut.clear();
		}
	}
	cout << j;
	return 0;
}
