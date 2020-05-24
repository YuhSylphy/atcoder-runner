#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

struct T {
	char type;
	ull cost;
};

void test(ull const& N, ull const& A, ull const& B, ull const& C, ull const& D) {
	vector<T> opt{{'A', A}, {'B', B}, {'C', C}, {'D', D}};
	sort(opt.begin(), opt.end(), [](T const& lhs, T const& rhs) { return lhs.cost < rhs.cost; });

	unordered_map<char, int> const mult{{'A', 2}, {'B', 3}, {'C', 5}};

	// unordered_map<char, T const&> map;
	// for(auto const& t: opt) {
	// 	map.insert_or_assign(t.type, t);
	// }

	// 唯一の要素は'D'(頭は必ず1つ足す)
	auto const di = static_cast<int>(
		distance(opt.begin(), find_if(opt.begin(), opt.end(), [](T const& t) { return t.type == 'D'; })));

	// for (auto x : opt) {
	// 	cout << x.type;
	// }
	// cout << " / " << di << endl;
	vector<int> op{di, 0};

	ull minimum = ULLONG_MAX;
	for (int cur = 1, costs = D; op.size() > 1;) {
		// cout << "cursor: " << cur << ", cost: " << costs << ", op: {";
		// for (auto x : op) {
		// 	cout << opt[x].type;
		// }
		// cout << "}, min: "  << minimum << endl;

		auto& i = op.back();
		// cout << "test " << i << ": " << opt[i].type << endl;
		if (i == di) {
			// Dの時は特別扱い: 残り全てをDで埋める
			// cout << "D++" << endl;
			auto const rest = N - cur;
			// cout << "  rest: " << rest << endl;;
			// オーバーフロー対策
			if (rest < (ULLONG_MAX - costs) / D) {
				auto const total = costs + rest * D;
				// cout << "  total: " << total << endl;;
				if (total < minimum) {
					cout << "upd: cursor: " << cur << ", cost: " << costs << ", op: {";
					for (auto x : op) {
						cout << opt[x].type;
					}
					cout << "+Dx" << rest << "}, min: " << minimum << ", total: " << total << endl;

					minimum = total;
				}
			}
		} else {
			auto const& t = opt[i];
			// cout << t.type << "! x" << mult.at(t.type) << endl;
			// オーバーフロー対策
			auto const m = mult.at(t.type);
			if (cur < ULLONG_MAX / m && costs < ULLONG_MAX - t.cost) {
				// 超えた場合
				if (N <= cur * m) {
					// Dで埋めて戻る
					// cout << "D--" << endl;
					auto const rest = cur * m - N;
					if (rest < (ULLONG_MAX - costs - t.cost) / D) {
						auto const total = costs + t.cost + rest * D;
						if (total < minimum) {
							cout << "upd: cursor: " << cur << ", cost: " << costs << ", op: {";
							for (auto x : op) {
								cout << opt[x].type;
							}
							cout << "+Dx" << rest << "}, min: " << minimum << ", total: " << total << endl;
							minimum = total;
						}
					}
				} else {
					// cout << "dive"<<  t.type << m << endl;
					cur *= m;
					costs += t.cost;

					op.push_back(0);
					continue;
				}
			}
		}
		++i;
		// cout << "increment " << (i - 1) << "->" << i << endl;
		for (auto i_ = i; i_ >= opt.size(); i_ = op.back()) {
			op.pop_back();

			// cout << "pop!"
			// 	 << "cursor: " << cur << ", cost: " << costs << ", op: {";
			// for (auto x : op) {
			// 	cout << opt[x].type << "(" << x << ")";
			// }
			// cout << "}, min: " << minimum << endl;

			auto j = op.back();

			// cout << "j: " << j << endl;

			if (j == di) {
				continue;
			}

			auto const& t = opt[j];
			// cout << "type: " << t.type << mult.at(t.type) << endl;
			// cout << "pop: " << t.type << mult.at(t.type) << endl;
			cur /= mult.at(t.type);
			costs -= t.cost;

			++op.back();
			// cout << "poped" << endl;
		}
	}
	cout << "ans:" << minimum << endl;
}

int main() {
	ull T, N, A, B, C, D;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> N >> A >> B >> C >> D;
		test(N, A, B, C, D);
	}

	return 0;
}
