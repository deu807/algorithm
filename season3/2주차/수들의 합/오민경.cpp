#include <iostream>
using namespace std;
int main() {
	long long N, sum = 0;
	int i = 1, count = 0;
	cin >> N;
    
	while (sum <= N) {
		sum += i;
		i++;
	}
	cout << i-1;
	return 0;
}