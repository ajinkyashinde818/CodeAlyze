#include <stdio.h>

int main(void){
    int n, c[200000];
    int i, j;
    int sub, maxv, minv;
    scanf("%d", &n);
    for (i=0; i <= n; i++){
        scanf("%d", &c[i]);
    } 
    
    maxv = 1 - 1000000000; //10^9
    minv = c[0];
    
    /*
    for (j=1; j <= n-1; j++){
        for (i=0; i <= j-1; i++){
            sub = c[j] - c[i];
            if (sub > maxv){
                maxv = sub;
            }
        }
    }
    */
    for (j=1; j <= n-1; j++){
        sub = c[j] - minv;
        if (maxv < sub){
            maxv = sub;
        }
        if (minv > c[j]){
            minv = c[j];
        }
    }
    
    printf("%d\n", maxv);
    return 0;
}
