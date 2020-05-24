#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void compareAndPush(ull index, ull value, vector<ull>& buf, deque<ull>& queue) {
	auto& current = buf[index];
	// cout << "cmp: " << index << " from " << current << " to " << value << endl;
	if (current > value) {
		cout << "upd: push" << index << endl;
		current = value;
		queue.push_back(index);
	}
}

//　端からメモリ不足
void test(ull const& N, ull const& A, ull const& B, ull const& C, ull const& D) {
	const auto size = N > ULLONG_MAX / 2 ? ULLONG_MAX : 2 * N;

	cout << "size: " << size << " (" << A << ", " << B << ", " << C << ", " << D << ")" << endl;
	// この枚数にするための最小コスト
	cout << "a" << endl;
	vector<ull> buf(size, ULLONG_MAX);
	cout << "b" << endl;
	deque<ull> queue;
	cout << "c" << endl;

	buf[0] = 0;
	buf[1] = D;
	queue.push_back(1ULL);
	while (!queue.empty()) {
		auto const i = queue.front();
		queue.pop_front();

		auto const n = buf[i];

		cout << "dequeue: " << i << "(" << n << ")" << endl;

		// 減らす
		compareAndPush(i - 1, n + D, buf, queue);
		// 増やす
		if (i < size) {
			compareAndPush(i + 1, n + D, buf, queue);
		} else
			continue;

		// 5倍
		if (i < size / 5) {
			compareAndPush(i * 5, n + C, buf, queue);
		} else
			continue;

		// 3倍
		if (i < size / 3) {
			compareAndPush(i * 3, n + B, buf, queue);
		} else
			continue;

		// 2倍
		if (i < size / 2) {
			compareAndPush(i * 2, n + A, buf, queue);
		} else
			continue;
	}
	cout << buf[N] << endl;
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
