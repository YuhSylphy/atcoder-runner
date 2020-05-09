#include <iostream>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	string S;
	cin >> S;
	auto ans = (S == "ABC" ? "ARC" : "ABC");

	cout << ans << endl;
	return 0;
}
