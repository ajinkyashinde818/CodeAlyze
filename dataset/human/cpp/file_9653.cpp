#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n,m;
std::vector<string> a,b;

bool check(int x, int y){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (a[x+i][y+j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	std::cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < b.size(); i++) {
		std::cin >> b[i];
	}

	for (int i = 0; i <= n-m; i++) {
		for (int j = 0; j <= n-m; j++) {
			if (a[i][j] == b[0][0]) {
				if (check(i, j)) {
					std::cout << "Yes" << '\n';
					return 0;
				}
			}
		}
	}

	std::cout << "No" << '\n';
	return 0;
}
