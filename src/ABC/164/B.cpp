#include <iostream>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	cout << (((C + B - 1) / B <= (A + D - 1) / D) ? "Yes" : "No") << endl;

	return 0;
}
