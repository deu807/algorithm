#include<bits/stdc++.h>
using namespace std;
long long S,sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> S;
	int temp = 0;
	while (sum<=S)
	{
		temp++;
		sum += temp;
		
	}
	cout << temp-1;
	
}