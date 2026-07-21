#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::string> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < m; l++) {
                    if (a[i + k][j + l] == b[k][l]) {
                        cnt++;
                    }
                }
            }

            if (cnt == m * m) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
}
