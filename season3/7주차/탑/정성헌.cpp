#include<bits/stdc++.h>
using namespace std;

int N;
stack<pair<int, int>>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;
        while (!s.empty())
        {
            if (s.top().second > height)
            {
                cout << s.top().first << " ";
                break;
            }
            else
                s.pop();
        }
        if (s.empty())
        {
            cout << 0 << " ";
        }
        s.push({ i,height });
    }
 }
