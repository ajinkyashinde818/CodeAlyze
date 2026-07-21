#include <stdio.h>

int main() {
    int n, a[100000], i, btn;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    i = 0;
    btn = 1;
    while (1) {
        int tmp;
        if (a[btn-1] == -1) {
            puts("-1");
            return 0;
        } else if (btn == 2) {
            printf("%d\n", i);
            return 0;
        }
        i++;
        tmp = a[btn-1];
        a[btn-1] = -1;
        btn = tmp;
    }
}
