#include<bits/stdc++.h>
using namespace std;

int N;
vector<int>v1, v2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v1.push_back(n);
        v2.push_back(n);
    }
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());   //  1,1,2,3,3,5 -> 1,2,3,5,1,3  -> 1,2,3,5  
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = v1.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (v1[mid] == v2[i])
            {
                cout << mid << ' ';
                break;
            }
            else if (v1[mid] < v2[i])
                left = mid + 1;
            else
                right = mid - 1;      
        
        }
    }
}
