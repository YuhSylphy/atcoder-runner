#include <iostream>
#include <vector>

using namespace std;

int
	main() {
	int N, Ai;
	cin >> N;

	vector<int> A(N);

	for (int i = 2; i <= N; ++i) {
		cin >> Ai;
		++A[Ai - 1];
	}

	for (int i = 0; i < N; ++i) {
		cout << A[i] << endl;
	}

	return 0;
}
