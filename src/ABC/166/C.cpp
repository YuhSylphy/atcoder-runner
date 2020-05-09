#include <boost/range/algorithm/count_if.hpp>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct T {
	ull height;
	bool good;
};

int main() {
	ull N, M;
	cin >> N >> M;
	vector<T> H;
	H.reserve(N);

	for (ull i = 0; i < N; ++i) {
		ull Hi;
		cin >> Hi;
		H.push_back({Hi, true});
	}

	for (ull j = 0; j < M; ++j) {
		int Aj, Bj;
		cin >> Aj >> Bj;
		if (H[Aj - 1].height <= H[Bj - 1].height) H[Aj - 1].good = false;
		if (H[Aj - 1].height >= H[Bj - 1].height) H[Bj - 1].good = false;
	}

	auto const ans = boost::range::count_if(
		H, [](T const& t) -> auto { return t.good; });
	cout << ans << endl;
	return 0;
}
