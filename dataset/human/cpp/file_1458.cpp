#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int n, k;
vector<int> ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i * (i - 1) <= 2 * n; ++i) {
        if (i * (i - 1) == 2 * n) {
            k = i;
            break;
        }
    }
    if (k == 0) {
        puts("No");
        return 0;
    }
    int cur = 0;
    for (int num = 0, i = k - 1; i > 0; --i, ++num) {
        for (int j = k - i; j < k; ++j) {
            ans[j].push_back(cur + j - k + i);
        }
        for (int j = cur; j < cur + i; ++j) {
            ans[num].push_back(j);
        }
        cur += i;
    }
    printf("Yes\n%d\n", k);
    for (int i = 0; i < k; ++i) {
        printf("%d ", ans[i].size());
        for (int x : ans[i]) {
            printf("%d ", x + 1);
        }
        printf("\n");
    }
    return 0;
}
