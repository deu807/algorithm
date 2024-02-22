#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<long long> v;
queue<long long> q;
int main()
{
    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        q.push(i);
        v.push_back(i);
    }

    while (!q.empty())
    {
        long long cur = q.front();
        int back = cur % 10;        //맨 뒷자리 수

        q.pop();

        // 맨 뒷자리 보다 작은 수 뒤에 넣기
        for (int i = 0; i < back; i++)
        {
            long long next = cur * 10 + i;
            q.push(next);
            v.push_back(next);
        }
    }

    if (n >= v.size())  cout << -1;     //범위 초과
    else    cout << v[n];

    return 0;
}