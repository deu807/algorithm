#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int A, B, answer=0;
vector<int> vc;
bool check1(int n) { //소수판별
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int check2(int n) {	//소인수분해 
	vc.clear();
	for (int i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			vc.push_back(i);
			n /= i;
		}
	}
	if (n > 1) {	
		vc.push_back(n);
	}
	return vc.size();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	for (int i = A; i <=B; i++) {
		int n  = check2(i);
		if (check1(n)) { answer++; }
	}
	cout << answer;
	return 0;
}