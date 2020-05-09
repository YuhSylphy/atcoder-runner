#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	ll K, A, B;
	cin >> K >> A >> B;

	auto ans = (A % K == 0 || (A / K + 1) * K <= B) ? "OK" : "NG";

	cout << ans << endl;
	return 0;
}
