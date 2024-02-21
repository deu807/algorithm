#include<bits/stdc++.h>
using namespace std;

int N;
vector<long long>v;
void solve(long long num)
{
    v.push_back(num);
    long long next = num % 10;
    while (next-- > 0) 
    {
        solve(num * 10 + next);
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < 10; i++)
    {
        solve(i);
    }
    sort(v.begin(), v.end());
    if (v.size() <= N) 
        cout << -1;
    else
        cout << v[N];

}
