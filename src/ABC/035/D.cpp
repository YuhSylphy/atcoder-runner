// dijkstra //////////////////////////////////////////
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using ll = long long;
using ull = unsigned long long;

namespace std {
template <typename L, typename R>
struct hash<pair<L, R>> : public unary_function<pair<L, R>, size_t> {
	size_t operator()(pair<L, R> const& p) const noexcept { return std::hash<L>()(p.first) ^ std::hash<R>()(p.second); }
};
} // namespace std

template <typename V = int, typename W = ull>
using dijkstra_edges = std::unordered_map<V, std::unordered_set<std::pair<W, V>>>;
template <typename V = int, typename W = ull>
using dijkstra_vertices = std::unordered_map<V, W>;

template <typename V = int, typename W = ull>
void dijkstra(V const& start, dijkstra_vertices<V, W>& d, dijkstra_edges<V, W> const& edges) {
	using T = std::pair<W, int>;
	using Q = std::priority_queue<T, std::vector<T>, std::greater<T>>;
	Q queue;
	queue.emplace(W(), start);
	d[start] = W();

	while (!queue.empty()) {
		auto const p = queue.top();
		auto const& pr = p.first;
		auto const& u = p.second;
		queue.pop();

		if (edges.count(u) < 1) continue;

		for (auto const& e : edges.at(u)) {
			auto const& weight = e.first;
			auto const& v = e.second;
			auto const alt = d[u] + weight;
			if (alt < d[v]) {
				d[v] = alt;
				queue.emplace(alt, v);
			}
		}
	}
}

template <typename V = int, typename W = ull, int Base = 1, template <typename> typename Container>
dijkstra_vertices<V, W>
	dijkstra(Container<V> const& keys, V const& start, W const& inf, dijkstra_edges<V, W> const& edges) {
	dijkstra_vertices<V, W> d(keys.size());
	for (auto const& k : keys) {
		d.emplace(k, inf);
	}
	dijkstra(start, d, edges);

	return d;
}

template <typename W = ull, int Base = 1>
dijkstra_vertices<int, W> dijkstra(int N, int start, W const& inf, dijkstra_edges<int, W> const& edges) {
	dijkstra_vertices<int, W> d(N);
	for (int i = Base; i < N + Base; ++i) {
		d[i] = inf;
	}
	dijkstra(start, d, edges);

	return d;
}
// dijkstra //////////////////////////////////////////

using namespace std;

int main() {
	ull N, M, T;
	cin >> N >> M >> T;

	vector<ull> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	dijkstra_edges<> F, R;

	for (int i = 0; i < M; ++i) {
		ull a, b, c;
		cin >> a >> b >> c;
		F[a].emplace(c, b);
		R[b].emplace(c, a);
	}

	auto const f = dijkstra(N, 1, numeric_limits<ull>::max(), F);
	auto const r = dijkstra(N, 1, numeric_limits<ull>::max(), R);

	auto ans = 0ULL;
	for (int i = 1; i <= N; ++i) {
		auto const& to = f.at(i);
		auto const& fro = r.at(i);
		if (T <= f.at(i) + r.at(i)) continue;
		auto const& time = T - f.at(i) - r.at(i);
		ans = max(ans, time * A[i - 1]);
	}

	cout << ans << endl;

	return 0;
}
