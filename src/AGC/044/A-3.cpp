/**
 * AC
 */

#include <deque>
#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ull costFor(
	ull const& n, ull const& N, ull const& A, ull const& B, ull const& C, ull const& D, unordered_map<ull, ull>& memo);

inline ull costWithFloorAndCeilFor(
	int const& mag, ull const& cost, ull const& n, ull const& N, ull const& A, ull const& B, ull const& C, ull const& D,
	unordered_map<ull, ull>& memo) {
	auto const r = n % mag;
	auto const f = n / mag;
	auto const c = r == 0 ? n / mag : n / mag + 1;
	// f(floor(n/mag)) + cost + D*x
	auto const lower = costFor(f, N, A, B, C, D, memo) + cost + (n - f * mag) * D;
	// f(ceil(n/mag)) + cost + D*x
	auto const upper = costFor(c, N, A, B, C, D, memo) + cost + (c * mag - n) * D;
	return min(lower, upper);
}

ull costFor(
	ull const& n, ull const& N, ull const& A, ull const& B, ull const& C, ull const& D, unordered_map<ull, ull>& memo) {
	if (memo.count(n) > 0) return memo.at(n);

	return memo[n] = min({
			   costFor(1, N, A, B, C, D, memo) + (n - 1) * D,
			   costWithFloorAndCeilFor(2, A, n, N, A, B, C, D, memo),
			   costWithFloorAndCeilFor(3, B, n, N, A, B, C, D, memo),
			   costWithFloorAndCeilFor(5, C, n, N, A, B, C, D, memo),
		   });
}

inline ull test(ull const& N, ull const& A, ull const& B, ull const& C, ull const& D) {
	unordered_map<ull, ull> memo{{0, 0}, {1, D}};
	return costFor(N, N, A, B, C, D, memo);
}

int main() {
	ull T, N, A, B, C, D;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N >> A >> B >> C >> D;
		cout << test(N, A, B, C, D) << endl;
	}

	return 0;
}
