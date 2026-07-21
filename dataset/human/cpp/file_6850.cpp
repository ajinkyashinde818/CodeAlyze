#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <numeric>
#include <queue>
#include <string>
#include <map>
#include <fstream>
#include <cassert>
#include <stack>
#include <climits>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <functional>
#include <cfloat>
constexpr long long int MOD = 1000000007LL;


int main() {
	int n; std::cin >> n;
	std::vector<int> a_num(n), b_num(n);
	for (auto& a : a_num) std::cin >> a;
	for (auto& b : b_num) std::cin >> b;
	std::vector<int> a_count(n + 1, 0), b_count(n + 1, 0);
	for (const auto a : a_num) a_count[a]++;
	for (const auto b : b_num) b_count[b]++;
	const auto comparator = [](const std::pair<int, int> a, const std::pair<int, int> b) {return a.second < b.second; };
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> queue(comparator);
	std::vector<int> a_free, b_free;
	for (auto i = 0; i <= n; ++i) {
		if (a_count[i] + b_count[i] > n) {
			std::cout << "No\n"; return 0;
		}
		if (a_count[i] > 0 &&  b_count[i] > 0) {
			queue.emplace(i, a_count[i] + b_count[i]);
		}
		else if (a_count[i] > 0) {
			a_free.push_back(i);
		}
		else if (b_count[i] > 0) {
			b_free.push_back(i);
		}
	}
	std::vector<std::pair<int, int>> result; result.reserve(n);
	while (queue.size() > 1) {
		const auto top = queue.top(); queue.pop();
		const auto second = queue.top(); queue.pop();
		result.emplace_back(top.first, second.first);
		--a_count[top.first];
		--b_count[second.first];
		{
			const auto i = top.first;
			if (a_count[i] > 0 && b_count[i] > 0) {
				queue.emplace(i, a_count[i] + b_count[i]);
			}
			else if (a_count[i] > 0) {
				a_free.push_back(i);
			}
			else if (b_count[i] > 0) {
				b_free.push_back(i);
			}
		}
		{
			const auto i = second.first;
			if (a_count[i] > 0 && b_count[i] > 0) {
				queue.emplace(i, a_count[i] + b_count[i]);
			}
			else if (a_count[i] > 0) {
				a_free.push_back(i);
			}
			else if (b_count[i] > 0) {
				b_free.push_back(i);
			}
		}
	}
	if (!queue.empty()) {
		const auto top = queue.top(); queue.pop();
		if (a_count[top.first] > b_count[top.first]) {
			for (auto i = 0; i < a_count[top.first]; ++i) {
				result.emplace_back(top.first, b_free.back());
				if (--b_count[b_free.back()] == 0) {
					b_free.pop_back();
				}
			}
			a_count[top.first] = 0;
			b_free.push_back(top.first);
		}
		else {
			for (auto i = 0; i < b_count[top.first]; ++i) {
				result.emplace_back(a_free.back(), top.first);
				if (--a_count[a_free.back()] == 0) {
					a_free.pop_back();
				}
			}
			b_count[top.first] = 0;
			a_free.push_back(top.first);
		}
	}
	while (result.size() < n) {
		result.emplace_back(a_free.back(), b_free.back());
		if (--a_count[a_free.back()] == 0) {
			a_free.pop_back();
		}
		if (--b_count[b_free.back()] == 0) {
			b_free.pop_back();
		}
	}
	std::sort(result.begin(), result.end(), [](const std::pair<int, int> a, const std::pair<int, int>b) {return a.first < b.first; });
	std::cout << "Yes\n";
	for (auto i = 0; i < n; ++i) {
		if (i > 0) std::cout << ' ';
		std::cout << result[i].second;
	}
	std::cout << '\n';
}
