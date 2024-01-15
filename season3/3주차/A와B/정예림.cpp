#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s, t;

	cin >> s;
	cin >> t;

	for (int i = t.size() - 1; i >= 0; i--)
	{
		if (t[i] == 'A') t.pop_back();
		else if (t[i] == 'B')
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}

		if (t == s)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}