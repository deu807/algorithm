#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int person[9];
	int sum = 0;
	int x, y;
	

	for (int i = 0; i < 9; i++)
	{
		cin >> person[i];
		
		sum += person[i]; //9명 키의 총합
	}

	sort(person, person + 9);

	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (sum - person[i] - person[j] == 100)
			{
				x = i;
				y = j;
			}
		}
	}
	
	for (int i = 0; i <9; i++)
	{
		if (i != x && i != y)
		{
			cout << person[i] << endl;
		}
		/*if (i == x || i == y) {

		}
		else
		{
			cout << person[i] << endl;
		}*/
	}
}