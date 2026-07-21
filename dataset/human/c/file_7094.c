#include <stdio.h>
#define rep(i, n) for(i = 0; i < n; i++)

int main(void) {
    int h, w, i, j;

    while(1) {
        scanf("%d %d", &h, &w);
        if(h == 0 && w == 0) break;
        rep(i, h) {
            rep(j, w) {
                if((i + j) % 2 == 0)
                    putchar('#');
                else
                    putchar('.');
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
