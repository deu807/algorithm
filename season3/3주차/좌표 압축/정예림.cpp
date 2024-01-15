#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, n;
vector<int>ev, ov;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> n;
        ev.push_back(n);
        ov.push_back(n);
    }

    // unique() : 중복된 원소를 벡터에서 제거       erase() : 특정 원소 지우기 - 범위 지정도 가능 erase(a, b)
    sort(ev.begin(), ev.end());     //-10,-9,2,4,4
    ev.erase(unique(ev.begin(), ev.end()), ev.end());       //-10,-9,2,4

    //이진탐색
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = ev.size() - 1;

        while (left <= right)
        {
            int avg = (left + right) / 2;

            if (ev[avg] == ov[i])
            {
                cout << avg << ' ';
                break;
            }
            else if (ev[avg] < ov[i])   left = avg + 1;
            else    right = avg - 1;
        }
    }
}
