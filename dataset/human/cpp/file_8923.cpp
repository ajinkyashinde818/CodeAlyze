#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

bool f(std::vector<std::string> v1, std::vector<std::string> v2, int a, int b) {
    for (int k = a; k < v2.size() + a; k++) {
        for (int l = b; l < v2.size() + b; l++) {
            if (v1[k][l] != v2[k - a][l - b]) return false;
        }
    }
    return true;
}

int main() {
    int n, m;

    std::cin >> n >> m;

    std::vector<std::string> v1(n), v2(m);

    for (int i = 0; i < n; i++) {
        std::cin >> v1[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> v2[i];
    }

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (f(v1, v2, i, j)) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}
