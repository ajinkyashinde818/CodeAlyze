#include<stdio.h>

int main(){
    long long A, B, C;
    long long ans;

    scanf("%lld %lld %lld", &A, &B, &C);

    if(B>=C){
        ans = B+C;
    }else if((A+B)>=C-1){
        ans = B+C;
    }else{
        ans = (A+B+1)+B;
    }

    printf("%lld", ans);

    return 0;
}
