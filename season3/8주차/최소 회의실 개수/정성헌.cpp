#include<bits/stdc++.h>
using namespace std;

int N,cnt,answer;
vector<pair<int, int>>v;
priority_queue<int, vector<int>, greater<int>>pq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int start = 0, end = 0;
        cin >> start >> end;
        v.push_back({ start,1 });
        v.push_back({ end,-1 });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i].second;
        answer = max(answer, cnt);
    }
    cout << answer;
}
