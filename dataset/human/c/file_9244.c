#include<stdio.h>

int main(void){
    int x, n, k, h[100000], i;

    scanf("%d%d",&n ,&k);
    for(i=0; i<n; i++){
        scanf("%d",&h[i]);
    }

    x = 0;  
    for(i=0; i<n; i++){
        if(h[i] >= k){
            x++;
        }
    }

    printf("%d\n",x);
    return 0;
}
