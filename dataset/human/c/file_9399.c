#include <stdio.h>

int main(void) {
    int n, d, x, a[100];
    
    scanf("%d", &n);
    scanf("%d%d", &d, &x);
    for(int i=0; i<n; i++) scanf("%d", a+i);
    
    for(int i=0; i<n; i++) {
        x += ((d-1)/a[i]+1);
    }
    
    printf("%d", x);
    return 0;
}
