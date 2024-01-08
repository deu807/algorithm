#include <iostream>
using namespace std;
int main() {
	long long N, sum = 0;
	int i = 1, count = 0;
	cin >> N;
	while (1) {
		sum += i;
		count++;
		if (sum > N) { count--; break; }
		i++;
	}
	cout << count << "\n";
	return 0;
}