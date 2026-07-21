#include<stdio.h>

int main(void){

    long int x,ans=0;

    scanf("%ld",&x);

    ans = (x / 11)*2;

    if(x % 11 == 0){
        ans = ans;
    }else if(x % 11 <= 6){
        ans += 1;
    }else if(x % 11 > 6){
        ans += 2;
    }

    printf("%ld",ans);
    return 0;
}
