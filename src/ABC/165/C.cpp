#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct T {
	ull a;
	ull b;
	ull c;
	ull d;
};

ull calc(vector<T> const& V, vector<ull> const& A) {
	ull r = 0;
	for (auto const& t : V) {
		if (A[t.b - 1] - A[t.a - 1] == t.c) r += t.d;
	}
	return r;
};

ull track(vector<T> const& V, vector<ull>& A, ull const N, ull const M, ull const upper, ull const& ix) {
	ull ret = 0;
	if (ix == N) {
		ret = calc(V, A);
	} else {
		for (ull Ai = (ix == 0 ? 1 : A[ix - 1]); Ai <= M; ++Ai) {
			A[ix] = Ai;
			ret = max(ret, track(V, A, N, M, upper, ix + 1));
			if (ret == upper) break;
		}
	}
	return ret;
};

int main() {
	ull N, M, Q;
	cin >> N >> M >> Q;
	vector<T> V;
	V.reserve(Q);

	vector<ull> A(N);

	ull upper = 0;
	for (ull i = 0; i < Q; ++i) {
		ull ai, bi, ci, di;
		cin >> ai >> bi >> ci >> di;
		V.push_back({ai, bi, ci, di});
		upper += di;
	}

	auto ans = track(V, A, N, M, upper, 0);

	cout << ans << endl;
	return 0;
}
