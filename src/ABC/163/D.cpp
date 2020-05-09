#include <iostream>

using namespace std;
using ll = long long;

int main() {
	auto const M = (int)1e9 + 7;
	ll N, K, R = 0;
	cin >> N >> K;

	for (ll k = K; k <= (N + 1); ++k) {
		auto const t = k * (N - k + 1) + 1;
		R = (R + t) % M;
	}

	cout << R << endl;
	return 0;
}
