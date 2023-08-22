#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n, k;
	// 1<= n <=100, 1<= k <= 10,000

	cin >> n >> k;

	vector<int> array(n);
	vector<int> dp(k + 1);

	for (int i = 0; i < n; i++)
		cin >> array[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = array[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - array[i]];
		}
	}
	cout << dp[k] << endl;


	return 0;
}