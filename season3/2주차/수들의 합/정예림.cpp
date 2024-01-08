#include <iostream>
using namespace std;

int main()
{
	long long S;
	long long sum = 0;
	int i = 0;

	cin >> S;

	while (S >= sum)
	{
		i++;
		sum += i;
		
	}
	cout << i-1;

	return 0;
}