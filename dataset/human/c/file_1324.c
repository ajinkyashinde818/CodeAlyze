#include <stdio.h>

#define N_MAX 200000

int n, m, a, b, i, is;
int is_from_one[N_MAX + 1];
int is_to_n[N_MAX + 1];

int main(void) {
    scanf("%d%d", &n, &m);
    
    for (i = 1; i <= m; ++i) {
        scanf("%d%d", &a, &b);
        if (a == 1) {
            is_from_one[b] = 1;
        } else if (b == n) {
            is_to_n[a] = 1;
        }
    }
    
    for (i = 1; i <= n; ++i) {
        //printf("%d from1, to n = %d, %d\n", i, is_from_one[i], is_to_n[i]);
        
        if (is_from_one[i] && is_to_n[i]) {
            is = 1;
        }
    }
    
    if (is) {
        puts("POSSIBLE");
    } else {
        puts("IMPOSSIBLE");
    }
    
    return 0;
}
