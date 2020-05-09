#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	double X;
	cin >> X;
	ull ans = 0LL;

	for (double r = 100.0; r < X; ++ans, r = floor(1.01 * r))
		;

	cout << ans << endl;
	return 0;
}
