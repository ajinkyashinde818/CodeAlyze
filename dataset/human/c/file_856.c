#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    long long int i, j, k, n, b, ans=0, po=0;
    scanf("%lld", &n);
    for(i=2; 1; i++){
        po=0;
        if(n%i==0){
        while(1){
            if(n%i==0){
                n = n/i;
                po++;
            }else break;
        }
        for(j=1; 1; j++){
            if(po>=j){
                po = po-j;
                ans++;
            }else break;
        }
        }
        if(n==1) break;
        if(i>1000000){
            ans += 1;
            break;
        }
    }
    printf("%lld", ans);
}
