#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	string S;
	cin >> S;

	auto const n = S.length();
	unordered_map<int, ull> U{{0, 1}}; // Tn を先に追加

	ll Tk = 0, d = 1;
	for (int k = n - 1; k >= 0; --k) {
		Tk = (Tk + d * (S[k] - '0')) % 2019;
		d = (10 * d) % 2019;
		++U[Tk];
	}

	ll ans = 0;
	for (auto& p : U) {
		ans += p.second * (p.second - 1) / 2;
	}

	cout << ans << endl;
	return 0;
}
