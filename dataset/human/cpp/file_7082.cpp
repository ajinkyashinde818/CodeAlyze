#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    reverse(b, b + n);

    int l = 0;
    int r = n - 1;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) continue;

        if (l < i && a[l] != b[i] && b[l] != a[i]) {
            swap(b[i], b[l]);
            l++;
        }
        else if (r > i && a[r] != b[i] && b[r] != a[i]) {
            swap(b[i], b[r]);
            r--;
        }
        else return 0 * printf("No\n");
    }

    printf("Yes\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) printf("%d", b[i]);
        else printf(" %d", b[i]);
    }
    printf("\n");
}
