#include <bits/stdc++.h>
using namespace std;
int n;
int check(int n) {
    for (int i = 1; i*(i-1)/2 <= n; i++) {
     //       cout << i << endl;
        if (i*(i-1)/2 == n) return i;
    }
    return 0;
}
int mp[505][505];
int main() {
    scanf("%d", &n);
    int k = check(n);
    if (!k) puts("No");
    else {
        puts("Yes");
        for (int i = 1; i <= k; i++)
            for (int j = i+1; j <= k; j++)
                mp[i][j] = mp[j][i] = n--;
        printf("%d\n", k);
        for (int i = 1; i <= k; i++) {
            printf("%d", k-1);
            for (int j = 1; j <= k; j++) {
                if (j == i) continue;
                printf(" %d", mp[i][j]);
            }
            puts("");
        }
    }
}
