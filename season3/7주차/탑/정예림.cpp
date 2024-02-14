#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
    pair : 2개의 데이터를 한 쌍으로 묶어서 다룰 때 사용
    인덱스와 수신탑의 높이를 같이 다루어야하기 때문
*/
int n;
stack<pair<int, int>>s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int high;
        cin >> high;

        while (!s.empty())
        {
            if (s.top().second > high)      //수신탑을 찾았을 때
            {
                cout << s.top().first << " ";
                break;
            }
            else        //수신탑을 찾을 때까지
                s.pop();
        }

        if (s.empty())      //수신탑이 없으면
        {
            cout << 0 << " ";
        }

        s.push({ i, high });
    }

    return 0;
}