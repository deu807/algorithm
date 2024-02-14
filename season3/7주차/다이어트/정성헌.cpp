#include<bits/stdc++.h>
using namespace std;

int G,Start=1,End=1;
vector<int>v; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> G;
    while (End<G)
    {
        if (End * End - Start * Start == G)
        {
            v.push_back(End);
            End++;
        }
        else if (End * End - Start * Start > G)
            Start++;
        else
            End++;
    }
    if (v.empty()) 
    {
        cout << -1 << '\n';
    }
    else 
    {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << '\n';
        }
    }

 }
