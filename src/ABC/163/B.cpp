#include <iostream>
using namespace std;

int main() {
	int N, M, A, R = 0;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> A;
		R += A;
	}
	cout << (N < R ? -1 : N - R) << endl;
	return 0;
}
