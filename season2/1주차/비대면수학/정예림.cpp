#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	int x, y;

	cin >> a >> b >> c >> d >> e >> f;
	y = (c * d - f * a) / (b * d - e * a);
	x = (e * c - b * f) / (e * a - b * d);
	cout << x << " " << y;
}