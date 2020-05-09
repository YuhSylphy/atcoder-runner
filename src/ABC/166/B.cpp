#include <iostream>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	ull N, K;
	cin >> N >> K;
	unordered_set<ull> S;

	for (ull i = 0; i < K; ++i) {
		ull di;
		cin >> di;
		for (ull j = 1; j <= di; ++j) {
			ull Aij;
			cin >> Aij;
			S.insert(Aij);
		}
	}
	auto const ans = N - S.size();
	cout << ans << endl;
	return 0;
}
