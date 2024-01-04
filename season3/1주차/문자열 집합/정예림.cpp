#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, M;
	int cnt = 0;
	string input;
	map<string, int>m;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		m.insert({ input, i });
	}

	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (m.find(input) != m.end()) cnt++;
	}

	cout << cnt;

	return 0;
}