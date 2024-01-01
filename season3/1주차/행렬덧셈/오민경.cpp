#include <iostream>
using namespace std;

int main() {
    int size1, size2;
    cin >> size1 >> size2; 
    int** array1 = new int* [size1]; 
    int** array2 = new int* [size1];
    int** answer = new int* [size1];
    for (int i = 0; i < size1; i++) {
        array1[i] = new int[size2];
        array2[i] = new int[size2];
        answer[i] = new int[size2];
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cin >> array1[i][j];
        }
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cin >> array2[i][j];
        }
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            answer[i][j] = array1[i][j] + array2[i][j];
            
        }
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cout << answer[i][j]<<" ";
        }
        cout << endl;
    }
    

    return 0;
}