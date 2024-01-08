#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<string>s;
vector<string>v;

int main()
{
	string number;
	int length = 1;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> number;
		reverse(number.begin(), number.end());
		v.push_back(number);
	}

	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			s.insert(v[i].substr(0, length));
		}
        
		if (s.size() == N)
		{
			break;
		}
		else
		{
			length++;
			s.clear();
		}
	}

	cout << length;

	return 0;
}