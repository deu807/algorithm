#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int* S = new int[100000]{0};
    int* A = new int[100000]{0};

    for (int x = 1; x <= N; ++x) {
        cin >> S[x];
        A[x] = A[x - 1] + S[x];
    }

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << A[j] - A[i - 1] << '\n';
    }

    delete[] S;
    delete[] A;

    return 0;
}