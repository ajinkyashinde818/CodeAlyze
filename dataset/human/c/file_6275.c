#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int* R;
    int i;
    int min;
    int diff;
    scanf("%d", &n);
    R = (int*)malloc(sizeof(int)*n);
    for ( i = 0; i < n; i++ ) {
        scanf("%d", &R[i]);
    }
    min = R[0];
    diff = R[1] - R[0];
    for ( i = 1; i < n; i++ ) {
        if ( R[i] - min > diff ) diff = R[i] - min;
        if ( min > R[i] ) min = R[i];
    }
    
    printf("%d\n", diff);
    
    free(R);
    return 0;
}
