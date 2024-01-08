#include<bits/stdc++.h>
using namespace std;
int N, k = 1;
set<string>s;
vector <string> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		v.push_back(str);
	}

	int temp = 1; 

	while (true)
	{

		for (int i = 0; i < v.size(); i++)
		{
			s.insert(v[i].substr(0, temp));
		}
		if (s.size() == N)
			break;
		else
		{
			temp++;
			k++;
			s.clear();
		}
	}
	cout << k;

}