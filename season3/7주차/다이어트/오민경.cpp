#include <iostream>
using namespace std;

long long N=1 , R= 1; //N = 현재 몸무게, R = 기억하고 있는 몸무게
int G;
bool exist = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G;

	while (N<=G) {
		if (N * N - R * R == G) {
			cout << N << endl;
			exist = true;
		}
		if (N * N - R * R > G) R++; 
		else N++;
	}
	if (!exist) cout << -1;

	return 0;
}