#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    char A[N][N];
    char B[M][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }

     for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> B[i][j];
        }
    }
    
    
    for (int i = 0; i <= N - M; ++i) {
        for (int j = 0; j <= N - M; ++j) {
            bool found = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (A[i + k][j + l] != B[k][l]) {
                        found = false;
                        break;
                    }
                }
                if (found == false) {
                    break;
                }
            }
            
            if (found == true) {
                std::cout << "Yes\n";
                return 0;
            }
        }
    }

    std::cout << "No\n";

    return 0;
}
