
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int N, M; //입력할 수의 개수

void solve(int x)
{
    int low = 0; //처음인덱스
    int high = a.size()- 1; //끝 인덱스
    int mid; //중간 인덱스

    while (low <= high) 
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            cout << 1 << '\n'; //특정 값을 찾았을 때
            return; 
        }
        else if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] > x)
            high = mid - 1;
    }
    cout << 0 << '\n'; //값을 찾지 못했을때 
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; //입력할 수의 개수

    for (int i = 0; i < N; i++)
    {
        int num; //입력할 수 
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end()); //이분탐색 위한 오름차순 정렬
    cin >> M; //입력할 수의 개수
    for (int i = 0; i < M; i++)
    {
        int X; //입력할 수 
        cin >> X;
        solve(X);
    }

    return 0;
}

