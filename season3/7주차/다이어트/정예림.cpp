#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int g;
long long s = 1, e = 1;
vector<int>v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> g;

	while (e < g)
	{
		if (pow(s, 2) - pow(e, 2) == g)		//가능한 현재 몸무게 찾기
		{
			v.push_back(s);
			s++;
		}
		else if (pow(s, 2) - pow(e, 2) < g)	s++;
		else e++;
	}

	if (v.empty()) cout << -1 << endl;
	else
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}

	return 0;
}