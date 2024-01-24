#include<bits/stdc++.h>
using namespace std;

long long dp[91], arr[91],N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
     dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4]=3;
    for (int i = 5; i <= N; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[N];
   
}