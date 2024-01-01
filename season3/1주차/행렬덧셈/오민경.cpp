#include <iostream>
using namespace std;

int main() {
    int size1, size2;
    cin >> size1 >> size2;
    int** array1 = new int* [size1 * 2];
    for (int i = 0; i < size1*2; i++) {
        array1[i] = new int[size2];
    }
    for (int i = 0; i < size1 * 2; i++) {
        for (int j = 0; j < size2; j++) {
            cin >> array1[i][j];
        }
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            array1[i][j] += array1[i + size1][j];
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}