#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, s, e, answer = 0, cnt = 0;
vector<pair<int, int>> v;
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;

        v.push_back({ s, 1 });
        v.push_back({ e, -1 });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i].second;

        if (answer < cnt)  answer = cnt;
    }

    cout << answer;

    return 0;
}