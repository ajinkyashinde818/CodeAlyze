#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

class DSU {
	std::vector<int> dat;

public:
	DSU(int n) : dat(n, -1) {}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			if (dat[x] > dat[y]) {
				std::swap(x, y);
			}
			dat[x] += dat[y];
			dat[y] = x;
		}
	}

	int find(int x) {
		if (dat[x] < 0) {
			return x;
		}
		return dat[x] = find(dat[x]);
	}

	int get_size(int x) {
		return -dat[find(x)];
	}
};

int main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a.back() ^= a[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		b.back() ^= b[i];
	}

	std::map<int, int> ma;
	std::map<int, int> mb;
	for (int i = 0; i <= n; i++) {
		ma[a[i]]++;
		mb[b[i]]++;
	}
	if (ma != mb) {
		puts("-1");
		return 0;
	}

	std::vector<int> dict(a.begin(), a.end());
	std::sort(dict.begin(), dict.end());
	dict.erase(std::unique(dict.begin(), dict.end()), dict.end());
	DSU dsu(dict.size());
	for (int i = 0; i <= n; i++) {
		a[i] = std::lower_bound(dict.begin(), dict.end(), a[i]) - dict.begin();
		b[i] = std::lower_bound(dict.begin(), dict.end(), b[i]) - dict.begin();
		dsu.unite(a[i], b[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] != b[i];
	}
	for (int i = 0; i < dict.size(); i++) {
		if (dsu.find(i) == i) {
			if (dsu.get_size(i) >= 2 && (dsu.find(i) != dsu.find(a.back()))) {
				ans++;
			}
		}
	}
	std::cout << ans << std::endl;
}
