#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0, count = 1;
    cin >> N;
    vector<int> height(N);
    for (int i = 0; i < N; i++)
        cin >> height[i];

    for (int i = N - 2; i >= 0; i--) {
        if (height[N - 1] < height[i]) { height[N - 1] = height[i]; count++; }
    }
    cout << count;
    return 0;
}