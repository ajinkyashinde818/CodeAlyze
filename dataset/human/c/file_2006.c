#include <stdio.h>
int main() {
    int a, b, c,ans;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b >= c) {
        ans = b + c;
    } else {
        if (c - 1 <= b) {
            ans = b + c;
        } else {
            ans = a + b + 1 + b;
        }
    }
    printf("%d\n", ans);
    return 0;
}
