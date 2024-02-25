#include <vector>
#include <iostream>
#include <string>
using namespace std;

int s, p, front, endd, answer;
string str;
vector<int> ACGT(100, 0);
vector<int> key(100, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> p;
	cin >> str;

	cin >> key['A'];
	cin >> key['C'];
	cin >> key['G'];
	cin >> key['T'];
	
	front = 0;
	endd = front + p - 1;

	for (int j = front; j <= endd; j++) {
		ACGT[str[j]]++;
	}

	while (endd < str.size()) {
		if (key['A'] <= ACGT['A'] && key['C'] <= ACGT['C'] &&key['G'] <= ACGT['G'] && key['T'] <= ACGT['T']) {
			answer++;
		}
		ACGT[str[front++]]--;
		ACGT[str[++endd]]++;
	}

	cout << answer;

	return 0;
}
