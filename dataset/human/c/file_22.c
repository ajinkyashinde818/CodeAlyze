#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n, i, j, k, r, g, b, ans=0;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    
    for(i=0; i*r<=n; i++){
        for(j=0; (i*r)+(j*g)<=n; j++){
            if((n-(i*r)-(j*g))%b == 0) ans++;
        }
    }
    printf("%d", ans);
    
}
