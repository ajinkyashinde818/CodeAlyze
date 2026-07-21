#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i,j,a[20] = {},b[50],c[50];
    int satisfy = 0;
    
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++) {
        scanf("%d",&b[i]);
    }
    for(i = 0; i < (n-1); i++) {
        scanf("%d",&c[i]);
    }
    
    for(i = 0; i < n; i++) {
        if(a[i] != 0) {
            j = a[i] - 1;
            satisfy += b[j];
            if(a[i] + 1 == a[i+1])
                satisfy += c[j];
        }
    }
    printf("%d",satisfy);
}
