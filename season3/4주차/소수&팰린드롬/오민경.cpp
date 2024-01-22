#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
bool check1(int n) { //소수인지 판별 -> 제곱근 이용 (2의 배수, 3의 배수 ... 겹치는 부분 제거)
	if (n < 2) return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
bool check2(string n) { //팰린드롬 판별
	string a = n;
	reverse(a.begin(), a.end());
	if (a == n) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i;
	cin >> N;
	i = N;
	while (true) {
		if (check1(i) && check2(to_string(i))) {
			cout<<i;
			break;
		}
		i++;
	}
	return 0;
}