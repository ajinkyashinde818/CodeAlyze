#include<stdio.h>

int main(void){

    long int A,B,tmp;
    long int x,r,ans;

    scanf("%ld %ld",&A,&B);

    x = A*B;

    if(A < B){
        tmp = A;
        A = B;
        B = tmp;
    }

    r = A % B;
    while(r != 0){
        A = B;
        B = r;
        r = A % B;
    }

    ans = x/B;

    printf("%ld\n",ans);
    return 0;
}
