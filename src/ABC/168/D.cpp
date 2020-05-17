#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

namespace std {
	template<typename Iterator>
	Iterator begin(pair<Iterator, Iterator> p) {
		return p.first;
	}
	template<typename Iterator>
	Iterator end(pair<Iterator, Iterator> p) {
		return p.second;
	}
}

bool search(
	deque<ll>& q,
	vector<ll>& v,
	unordered_multimap<ll, ll>& e
) {
	while(!q.empty()){
		auto const current = q.front();
		q.pop_front();

		// traverse edges
		for(auto const& [_, neighbor]: e.equal_range(current)) {
			if(v[neighbor - 1] == 0) { // if not yet marked
				v[neighbor - 1] = current; // mark as
				q.push_back(neighbor); // in next step
			}
		}
	}
	return true;
}

int main() {
	ll N, M;
	cin >> N >> M;
	deque<ll> q; // 幅優先探索キュー
	vector<ll> v(N); // 道しるべ
	unordered_multimap<ll, ll> e; // 通路

	for(int i=1; i<=M; ++i) {
		ll Ai, Bi;
		cin >> Ai >> Bi;
		e.emplace(Ai, Bi);
		e.emplace(Bi, Ai);
	}

	q.push_back(1); // 入口から探索開始

	auto const& res = search(q, v, e);

	if (res) {
		cout << "Yes" << endl;
		for(int i=2; i<=N; ++i) {
			cout << v[i-1] << endl;
		}
	} else {
		cout << "No" << endl;
	}

	return 0;
}
