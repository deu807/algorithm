#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int n, sum = 0;
int card;
priority_queue<int, vector<int>, greater<int>>q;		//우선순위큐 오름차순 정렬
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> card;
		q.push(card);
	}

	while (q.size() > 1)
	{
		int a = q.top();
		q.pop();

		int b = q.top();
		q.pop();

		sum += a + b;
		q.push(a + b);
	}

	cout << sum;

	return 0;
}