#include <stdio.h>
#define N 100000

int main(void){
    int n,k;
    int h[N];
    int i;
    int count = 0;
    
    scanf("%d %d", &n, &k);
    
    for(i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }
    
    for(i = 0; i < n; i++){
        if(h[i] >= k){
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
