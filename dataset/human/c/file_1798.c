#include <stdio.h>

int main(void){
    int n, total = 0;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n-1; i++) {
        scanf("%d", &c[i]);
    }
    for(int i = 0; i < n; i++) {
        total += b[a[i]-1];
        if(i > 0) {
            if(a[i-1] + 1 == a[i]) {
                total += c[a[i-1]-1];
            }
        }
    }
    printf("%d\n", total);
    return 0;
}
