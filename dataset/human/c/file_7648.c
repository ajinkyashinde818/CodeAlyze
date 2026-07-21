#include<stdio.h>

int main(void) {
    int a[10000] = {};
    int i, j;
    
    for(i = 0; i < 10000; i++) {
        scanf("%d", &a[i]);
        if(a[i] == 0) {
            break;
        }
    }
        
    for(j = 0; j < i; j++) {
        printf("Case %d: %d\n", j + 1, a[j]);
    }
    
    return 0;
}
