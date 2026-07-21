#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>

class UnionFind {
	std::vector<int> vec;
public:
	UnionFind(int size) : vec(size, -1) {};
	int find(int a) {
		return vec[a] < 0 ? a : vec[a] = find(vec[a]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	int size_of(int a) {
		return -vec[find(a)];
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a != b) {
			if (vec[b] < vec[a]) std::swap(a, b);
			vec[a] += vec[b];
			vec[b] = a;
		}
	}
};
using mapped_tree = std::tuple<std::vector<std::vector<int>>, std::vector<int>, std::vector<int>>;

mapped_tree shrink_tree(const std::vector<std::vector<int>>& nodes, const std::vector<bool> &is_white, const std::vector<int>& base_node, int time) {
	UnionFind uft(nodes.size());
	for (auto i = 0; i < nodes.size(); ++i) if (base_node[i] != time) {
		for (const auto j : nodes[i]) if (i < j && is_white[i] == is_white[j] && base_node[j] != time) {
			uft.unite(i, j);
		}
	}
	std::vector<int> old_to_new(nodes.size()), node_size(nodes.size(), 0);
	for (auto i = 0; i < nodes.size(); ++i) {
		old_to_new[i] = uft.find(i);
		node_size[old_to_new[i]]++;
	}
	std::vector<std::vector<int>> new_nodes(nodes.size());
	for (auto i = 0; i < nodes.size(); ++i) {
		for (const auto j : nodes[i]) if (old_to_new[i] != old_to_new[j]) {
			new_nodes[old_to_new[i]].push_back(old_to_new[j]);
		}
	}
	return std::make_tuple(new_nodes, old_to_new, node_size);
}
struct Query {
	int type, vertex;
};
int main() {
	int n, q; std::cin >> n >> q;
	std::vector<std::vector<int>> nodes(n);
	for (auto i = 1; i < n; ++i) {
		int a, b; std::cin >> a >> b;
		nodes[--a].push_back(--b);
		nodes[b].push_back(a);
	}
	std::vector<Query> query; query.reserve(q);
	std::vector<int> change_count; change_count.reserve(q);
	for (auto i = 0; i < q; ++i) {
		int t, v; std::cin >> t >> v;
		query.push_back(Query{ t, v - 1 });
		change_count.push_back(2 - t);
		if (i > 0) change_count[i] += change_count[i - 1];
	}
	std::vector<bool> is_white(n, true);
	std::vector<int> is_searched(n, -1), base_node(n, -1);
	const int sqrt = std::sqrt(n);
	for (auto i = 0; i < q; ) {
		const auto end = std::distance(change_count.begin(), std::upper_bound(change_count.begin(), change_count.end(), change_count[i] + sqrt));
		for (auto j = i; j < end; ++j) {
			if (query[j].type == 1) {
				base_node[query[j].vertex] = i;
			}
		}
		const auto shrinked = shrink_tree(nodes, is_white, base_node, i);
		for (auto j = i; j < end; ++j) {
			if (query[j].type == 1) {
				is_white[std::get<1>(shrinked)[query[j].vertex]] = !is_white[std::get<1>(shrinked)[query[j].vertex]];
			}
			else {
				std::stack<int> stack; stack.push(std::get<1>(shrinked)[query[j].vertex]);
				is_searched[stack.top()] = j;
				int count = std::get<2>(shrinked)[stack.top()];
				while (!stack.empty()) {
					const auto top = stack.top(); stack.pop();
					for (const auto next : std::get<0>(shrinked)[top]) if (is_searched[next] != j && is_white[next]) {
						count += std::get<2>(shrinked)[next];
						is_searched[next] = j;
						stack.push(next);
					}
				}
				std::cout << count << std::endl;
			}
		}
		i = end;
	}
}
