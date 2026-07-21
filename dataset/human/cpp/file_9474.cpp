#include <iostream>
#include <cstdio>

std::string s[51], t[51];
int n, m;

bool search(int x, int y) {
    int cnt = 0;
    for (int i = x; i < x+m && i < n; ++i) {
        for (int j = y; j < y+m && j < n; ++j) {
            if (cnt == m*m) return true;
            if (s[i][j] != t[i-x][j-y]) return false;
            else cnt++;
        }
    }
    if (cnt != m*m) return false;
    return true;
}

int main() {

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> t[i];
    }

    bool flag = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) { 
            if (s[i][j] == t[0][0]) {
                flag = search(i, j);
                if (flag) goto END;
            }
        }
    }
    END:
    if (flag) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
