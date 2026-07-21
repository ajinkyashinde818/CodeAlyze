#include <stdio.h>
int main(void){
    int k, i, cnt;
    long n;
    int h[100000];
    
    scanf("%ld %d", &n, &k);
    for(i = 0; i < n;  i++){
        scanf("%d", &h[i]);
    }
    
    cnt = 0;
    
    for(i = 0; i < n; i++){
        if(h[i] >= k){
            cnt = cnt + 1;
        }
    }
    
    printf("%d", cnt);
}
