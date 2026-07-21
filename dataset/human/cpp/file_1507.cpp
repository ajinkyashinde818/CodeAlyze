#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
vector<int> num[maxn], G[maxn];
bool used[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i * (i + 1) / 2 > n) continue;
        if (i * (i + 1) / 2 == n) {
            printf("Yes\n%d\n", i + 1);
            for (int j = 1, x = 0; j <= i; j++) {
                for (int k = 1; k <= j; k++) {
                    num[j].push_back(++x);
                }
            }
            for (int j = 1; j <= i; j++) {
                for (int k = 1; k <= j; k++) {
                    G[j].push_back(num[j][k - 1]);
                }
                for (int k = j + 1; k <= i; k++) {
                    G[j].push_back(num[k][j - 1]);
                }
            }
            for (int j = 1; j <= i; j++) {
                G[i + 1].push_back(num[j].back());
            }
            for (int j = 1; j <= i + 1; j++) {
                printf("%d ", G[j].size());
                for (int k : G[j]) {
                    printf("%d ", k);
                }
                printf("\n");
            }
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
