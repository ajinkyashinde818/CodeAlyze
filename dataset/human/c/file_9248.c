#include <stdio.h>

int main(void){

    int n, k, h[100000], i, x=0;

    scanf("%d%d", &n, &k);

    for(i=0;i<n;i++){
        scanf("%d", &h[i]);
        if(h[i] >= k)
        x = x + 1;
    }

    printf("%d\n", x);

    return 0;
    
}
