#include <iostream>
#include <set>

using namespace std;

int main() {
	set<string> S;
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string Si;
		cin >> Si;
		S.insert(move(Si));
	}
	cout << S.size() << endl;
	return 0;
}
