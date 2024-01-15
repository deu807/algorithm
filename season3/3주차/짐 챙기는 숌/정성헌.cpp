#include<bits/stdc++.h>
using namespace std;

int N, M,arr[51],answer=1,sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        if (M >= sum + arr[i])
            sum += arr[i];
        else
        {
            answer++;
            sum = arr[i];
        }
    }

    if (N == 0)
        cout << 0;
    else
        cout<<answer;
}
