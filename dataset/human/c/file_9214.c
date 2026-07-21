#include <stdio.h>

int main(void) {
    int n, k, h[100100], count = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        if(h[i] >= k) count++;
    }
    printf("%d\n", count);
    return 0;
}
