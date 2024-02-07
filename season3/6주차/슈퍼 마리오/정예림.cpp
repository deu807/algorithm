#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int score[10];
int sum = 0;
int answer = 0;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> score[i];
	}

	for (int i = 0; i < 10; i++)
	{
		sum += score[i];

		if (abs(100 - sum) < abs(100 - answer)) answer = sum;
		else if (abs(100 - sum) == abs(100 - answer)) answer = max(sum, answer);
	}

	cout << answer;

	return 0;
}