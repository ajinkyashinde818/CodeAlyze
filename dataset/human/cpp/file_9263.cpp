#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<char>> N, M;

bool check(int a, int b) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            //std::cout << i << " " << j << std::endl;
            if(N[i + a][j + b] != M[i][j])
                return false;
        }
    }
    
    return true;
}

int main() {
    std::cin >> n >> m;
    
    N.resize(n, std::vector<char>(n));
    M.resize(m, std::vector<char>(m));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> N[i][j];
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            std::cin >> M[i][j];
        }
    }
    
    for(int i = 0; i <= n - m; ++i) {
        for(int j = 0; j <= n - m; ++j) {
            //std::cout << i << " " << j << std::endl;
            if(check(i, j)) {
                std::cout << "Yes" << std::endl;
                
                return 0;
            }
        }
    }
    
    std::cout << "No" << std::endl;
}
