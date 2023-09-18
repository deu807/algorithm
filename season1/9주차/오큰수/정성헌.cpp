#include <iostream>
#include <stack>
using namespace std;

int N, arr[1000001], ans[1000001], num;

int main()
{
	stack<int> s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;

		while (!s.empty() && arr[s.top()] < num)
		{
			ans[s.top()] = num;
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		ans[s.top()] = -1;
		s.pop();
	}



	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}
}
