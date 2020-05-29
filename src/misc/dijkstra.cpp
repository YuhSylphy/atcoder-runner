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
		auto const [pr, u] = queue.top();
		queue.pop();

		if (edges.count(u) < 1) continue;

		for (auto const& [weight, v] : edges.at(u)) {
			auto const alt = d[u] + weight;
			if (alt < d[v]) {
				d[v] = alt;
				queue.emplace(alt, v);
			}
		}
	}
}

template <typename Container, typename V = int, typename W = ull, int Base = 1>
dijkstra_vertices<V, W>
	dijkstra(Container const& keys, V const& start, W const& inf, dijkstra_edges<V, W> const& edges) {
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

template <typename V, typename W>
void view(dijkstra_vertices<V, W> const& d) {
	for (auto const& [u, w] : d) {
		std::cout << "{ " << u << ", " << w << " }" << std::endl;
	}
}

int main() {
	std::vector fs{[]() {
		std::vector<char> V{'A', 'B', 'C', 'D', 'E', 'F'};
		dijkstra_edges<char> E{
			{'A', {{7, 'B'}, {2, 'C'}}},
			{'B', {{7, 'A'}, {7, 'C'}, {1, 'D'}, {6, 'E'}}},
			{'C', {{2, 'A'}, {7, 'B'}, {6, 'D'}, {5, 'E'}}},
			{'D', {{1, 'B'}, {6, 'C'}, {6, 'E'}, {1, 'F'}}},
			{'E', {{6, 'B'}, {5, 'C'}, {6, 'D'}, {1, 'F'}}},
			{'F', {{1, 'D'}, {1, 'E'}}},
		};
		return dijkstra(V, 'A', ULLONG_MAX, E);
	}};
	for (auto const& f : fs) {
		auto const forward = f();
		view(forward);
	}

	return 0;
}
