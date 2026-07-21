#include <stdio.h>

int main(int argc, char *argv[]) {
    int n, k, s;
    int l;
    int a[100000];
    int i;
    
    scanf("%d %d %d", &n, &k, &s);
    
    for (i = 0; i < k; i++) {
        a[i] = s;
    }
    
    for (i = k; i < n; i++) {
        if (s == 1000000000) {
            a[i] = 1000000000 - 1;
        } else {
            a[i] = s + 1;
        }
    }
    
    printf("%d", a[0]);
    for (i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
    
    return 0;
}
