#include<bits/stdc++.h>
using namespace std;

int N;
bool check1(int n)
{
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool check2(string s)
{
    for (int i = 0; i < s.size()/2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    while (true)
    {
        if (check1(N) && check2(to_string(N)))
        {
           cout << N;
           break;
        }
        N++;
    }

}