#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct MyValue {
	int value, order;

	MyValue(int value, int order) {
		this->value = value;
		this->order = order;
	}
	bool operator<(const MyValue& rhs) {
		return order < rhs.order;
	}
	bool operator>(const MyValue& rhs) {
		return order > rhs.order;
	}
};

int main() {
	int n, m;
	std::vector<int> e;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; std::cin >> a;
		e.push_back(a);
	}

	std::vector<MyValue> v; // 値, 順番
	v.reserve(n + 1);
	v.push_back(MyValue(0, -99999999));
	for (int i = 0; i < n; i++) {
		v.push_back(MyValue(i + 1, i + 1));
	}

	for (int i = 0; i < m; i++) {
		v[e[i]].order = -i;
	}

	std::sort(v.begin(), v.end());

	for (int i = 1; i < v.size(); i++) {
		std::cout << v[i].value << std::endl;
	}

	return 0;
}
