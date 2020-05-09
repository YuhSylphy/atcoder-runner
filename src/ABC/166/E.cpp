#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	ull N;
	cin >> N;
	unordered_map<ll, ll> pos, neg;

	for (auto i = 1; i <= N; ++i) {
		ull Ai;
		cin >> Ai;
		++pos[i + Ai];
		++neg[i - Ai];
	}

	auto ans = 0ull;
	for (auto [k, v] : pos) {
		ans += v * neg[k];
	}
	cout << ans << endl;
	return 0;
}
