#include<bits/stdc++.h>
using namespace std;

string S, T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    cin >> T;
    while (S.size() != T.size())
    {
        if (T[T.size() - 1] == 'A')
            T.pop_back();
        else
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    if (S.compare(T)==0)
        cout << 1;
    else
        cout << 0;

}
