#include <iostream>
#include <cmath>
using namespace std;

bool check(int num) //소수 판별
{
	if (num < 2) return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true; //소수일시 true
}
void solve(int firstnum, int count)
{
	if (count == 0)
	{
		cout << firstnum<<'\n';
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		int temp = firstnum * 10 + i;
		if (check(temp))
			solve(temp, count - 1); //재귀함수 
	}
}

int main()
{
	int N;  //자리 수 
	cin >> N;
	
	int firstnum[4] = { 2,3,5,7 }; // 첫 번째 자리에 올 수 있는 수 
	for (int i = 0; i < 4; i++)
	{
		solve(firstnum[i], N-1); //첫 번째 수는 이미 받았기때문에 N-1
	}
}