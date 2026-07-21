#include <bits/stdc++.h>
using namespace std;
int f(int m) {
    return m * (m - 1) / 2;
}

int id[500][500];
int cnt;
int get(int x, int y) {
    if (x > y) swap(x, y);
    if (id[x][y]) return id[x][y];
    return id[x][y] = ++cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int m = 1; f(m) <= n; m++) {
        if (f(m) == n) {
            puts("Yes");
            printf("%d\n", m);
            for (int i = 0; i < m; i++) {
                printf("%d ", m - 1);
                for (int j = 1; j < m; j++) {                    
                    printf("%d%c", get(i,(i+j)%m), " \n"[j == m - 1]);
                }

            }

            return 0;
        }
    }
    puts("No");

}
