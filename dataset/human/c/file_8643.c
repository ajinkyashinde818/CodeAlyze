#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];
    int hist[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hist[i] = 0;
    }

    int flag = 0, next = 1, cnt = 0;
    while (1) {
        next = a[next - 1];
        cnt++;

        if (hist[next - 1]) {
            break;
        }

        if (next == 2) {
            flag = 1;
            break;

        }
        hist[next - 1] = 1;
    }

    if (flag) {
        printf("%d\n", cnt);
    } else {
        printf("%d\n", -1);
    }

    return 0;
}
