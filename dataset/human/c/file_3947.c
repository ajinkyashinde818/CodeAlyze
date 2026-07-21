#include <stdio.h>

int main()
{
    int A,B,K;
    int num[100];
    int i,tmp = 0;

    scanf("%d%d%d",&A,&B,&K);

    int ban;
    if(A<B){
        ban = A;
    }else{
        ban = B;
    }

    for(i=1;i<=ban;i++){
        if(A%i == 0 && B%i == 0){
            num[tmp] = i;
            tmp++;
        }
    }

    printf("%d",num[tmp - K]);
    return 0;
}
