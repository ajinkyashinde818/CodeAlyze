#include <stdio.h>
int main() {
    short int n, cnt = 0, max = 0;
    scanf("%hi", &n);
    for (short int i = 0; i < n; i++) {
        short int a, b;
        scanf("%hi%hi", &a, &b);
        if (a == b) {
            cnt++;
        }
        if (max < cnt) max = cnt;
        if (a != b) {
            cnt = 0;
        }
    }
    if (max >= 3) {
        printf("Yes");
    }
    else printf("No");
}
