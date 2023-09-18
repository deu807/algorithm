#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL); 
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int N, arr[2001] = {}, start = 0, end = 0, answer=0; //수의 개수,입력값넣어줄배열,포인터변수 2개,좋은 수
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	
	for (int i = 0; i < N; i++)
	{
		start = 0;
		end = N - 1;

		while (start < end)
		{
			if (arr[start] + arr[end] > arr[i])
			{
				end--;
			}
			else if (arr[start] + arr[end] < arr[i])
			{
				start++;
			}
			else if(arr[start]+arr[end]==arr[i])
			{
				if (start != i && end != i)
				{
					answer++;
					break;
				}
				else if (i == start)
					start++;
				else if (i == end)
					end--;
			}
			
		}
	}
	cout << answer << '\n';
}