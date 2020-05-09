#include <iostream>
#include <tuple>

using namespace std;
using ll = long long;
using ull = unsigned long long;

tuple<ll, ll> calc(ll const& X) {
	for (auto A = 1ll;; ++A) {
		auto const T = X - A * A * A * A * A;
		if (T == 0) return {A, 0};
		auto const sign = T > 0 ? 1ll : -1ll;
		auto const U = T * sign;
		for (auto B = 1ll, B5 = B * B * B * B * B; B5 <= U; ++B, B5 = B * B * B * B * B) {
			if (B5 == U) return {A, -1 * sign * B};
		}
	}
}

int main() {
	ll X;
	cin >> X;

	auto const [A, B] = calc(X);

	cout << A << " " << B << endl;
	return 0;
}
