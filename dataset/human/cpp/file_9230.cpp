#include <iostream>

char a[50][50], b[50][50];

int main() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> a[i][j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> b[i][j];
	
	for (int i = 0; i <= n - m; ++i) {
		for (int j = 0; j <= n - m; ++j) {
			bool isMatch = true;

			for (int k = 0; k < m; ++k)
				for (int l = 0; l < m; ++l)
					isMatch &= (a[i + k][j + l] == b[k][l]);

			if (isMatch) {
				std::cout << "Yes" << std::endl;
				return 0;
			}
		}
	}

	std::cout << "No" << std::endl;
}
