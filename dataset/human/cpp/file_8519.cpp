#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using lint = long long;

int main() {
    lint N, M; std::cin >> N >> M;
    std::vector<std::string> A(N);
    std::vector<std::string> B(M);
    for (auto& r : A)std::cin >> r;
    for (auto& r : B)std::cin >> r;
    if (N == M) {
        bool flag = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] != B[i])
                flag = false;
        }
        if (flag == true) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        else {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    for (int h = 0; h < N - M; ++h) {
        for (int w = 0; w < N - M; ++w) {
            bool flag = true;
            for (int j = 0; j < M; ++j) {
                if (A[h + j].substr(w, M) != B[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
}
