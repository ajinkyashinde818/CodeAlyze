#include <stdio.h>
int main(void){
    int a, b, k, i, ans = 0;
    
    scanf("%d %d %d", &a, &b, &k);
    
    if(a >= b){
        i = a;
    }else{
        i = b;
    }
    for(;;){
        if(a % i == 0 && b % i == 0){
            ans = i;
            k = k - 1;
            if(k == 0){
                printf("%d\n", ans);
                break;
            }
        }
        i = i - 1;
    }
}
