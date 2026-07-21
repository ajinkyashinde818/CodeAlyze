#include <iostream>
#include <array>

using ar = std::array<std::array<char, 50>, 50>;

bool finder(const ar& a, const ar& b, const int M, const int i, const int j);

int main() {
	ar a = {};
	ar b = {};

	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char c;
			std::cin >> c;
			a[i][j] = c;
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;
			std::cin >> c;
			b[i][j] = c;
		}
	}

	int m = N - M;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (finder(a, b, M, i, j)) {
				std::cout << "Yes" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}

bool finder(const ar& a, const ar& b, const int M, const int i, const int j) {
	for (int k = 0; k < M; ++k) {
		for (int l = 0; l < M; ++l) {
			if (a[i + k][j + l] != b[k][l]) {
				return false;
			}
		}
	}
	return true;
}
