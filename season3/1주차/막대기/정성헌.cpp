#include <iostream>
#include <stack>
using namespace std;
int N, h,answer,temp;
stack<int>s;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h;
		s.push(h);
	}

	while (!s.empty())
	{
		if (temp < s.top())
		{
			temp = s.top();
			answer++;
		}
		s.pop();
	}
	cout << answer;
}