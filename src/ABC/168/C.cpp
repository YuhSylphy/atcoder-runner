#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	ll A, B, H, M;
	cin >> A >> B >> H >> M;
	auto ans = sqrt(A*A+B*B-2*A*B*cosl(11 * M_PI * (60 * H + M) / 360));

	cout << setprecision(numeric_limits<double>::max_digits10) << ans << endl;
	return 0;
}
