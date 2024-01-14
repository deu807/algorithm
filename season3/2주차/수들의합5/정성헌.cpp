#include<bits/stdc++.h>
using namespace std;
int N, Start = 1, End = 1, answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int sum = 1;
    while (End <= N) {
        if (sum == N) 
        {
            answer++; 
            sum -= Start++;
        }
        else if (sum < N)
        {
            sum += ++End;
        }
        else 
        {
            sum -= Start++;
        }
    }
    cout << answer;
}
