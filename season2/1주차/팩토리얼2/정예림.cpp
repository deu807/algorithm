#include <iostream>
using namespace std;
long long f(long long a);

int main()
{
	long long n;

	cin >> n;

	if (n != 0)
	{
		cout <<f(n);
	}
	else
		cout << "1";
}
long long f(long long a)
{
	/*if (a == 1) return 1;
	else return a*f(a - 1);*/
	return a == 1 ? 1 : a * f(a - 1);
}