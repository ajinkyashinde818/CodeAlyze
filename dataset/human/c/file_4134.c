#include <stdio.h>
#include <math.h>

int main(void){
    
    int a, b, k;
    int c=101;
    int ans = 3;
    
    scanf("%d %d %d", &a ,&b, &k);
    
    for(int i=100; i>0; i--){
        c--;
        if(b%c==0 && a%c==0){
            ans = c;
            k--;
            if(k==0) break;
        }
    }
    
    printf("%d", ans);
}
