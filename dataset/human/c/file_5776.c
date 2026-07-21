#include<stdio.h>

int main() {
    int n, i, min, dmax;
    int r[200000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &r[i]);
    
    min = r[0];
    dmax = r[1] - r[0];
    
    for (i = 1; i < n; i++){
        if(r[i] - min > dmax)
            dmax = r[i] - min;
        if (r[i] < min)
            min = r[i];
    }
    printf("%d\n", dmax);
    
}
