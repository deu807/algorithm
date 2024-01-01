#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	int** array1 = new int* [x];
	int** array2 = new int* [x];
	int** result = new int* [x];
	for (int i = 0; i < x; i++)
	{
		array1[i] = new int[y];
		array2[i] = new int[y];
		result[i] = new int[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> array1[i][j];
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> array2[i][j];
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			result[i][j] = array1[i][j] + array2[i][j];
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}