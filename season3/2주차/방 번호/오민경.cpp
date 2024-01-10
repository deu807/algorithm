#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, set = 1;
	int number[10] = { 0 }; //0~9 숫자 개수 저장
	cin >> n;
	while (n > 0) {
		number[n % 10]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++) { //0~5, 7~8일 때 
		if (i == 6 || i == 9){		
			continue;
		}
		set = max(set, number[i]);
	}
	set = max(set, (number[6] + number[9]+1) / 2);	//6일 때와 9일 때의 최댓값 
	cout << set;
	return 0;
}
