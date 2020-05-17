#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	ll K;
	string S;
	cin >> K >> S;
	auto ans = S.size() <= K ? S : (S.substr(0, K) + "...");

	cout << ans << endl;
	return 0;
}
