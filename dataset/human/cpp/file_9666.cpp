#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 53;

int n, m;
char a[MAXN][MAXN], b[MAXN][MAXN];

bool contain(int r, int c) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[r + i][c + j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool judge() {
    for(int i = n - m; i >= 0; --i) {
        for(int j = n - m; j >= 0; --j) {
            if(contain(i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    while(2 == scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", a[i]);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%s", b[i]);
        }
        printf("%s\n", judge() ? "Yes" : "No");
    }
    return 0;
}
