#include <iostream>
using namespace std;

int N, arr[101][101];

int main()
{
	
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
		
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j]<<' ';
		}
		cout << endl;
	}
}