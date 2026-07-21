#include <stdio.h>
#include <stdlib.h>

#define LINE_BUF_SIZE  1024

int main(void) {
    static char line[LINE_BUF_SIZE];

    int n;
    int i;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    int c = 0;
    int now = 0;

    for (;;) {
        if (c >= n) {
            printf("%d\n", -1);
            break;
        } else if (now == 1) {
            printf("%d\n", c);
            break;
        }
        c++;
        now = a[now]-1;
    }

    return 0;
}
