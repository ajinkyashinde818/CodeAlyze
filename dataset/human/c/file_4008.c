//b.c B-K-th Common Divisor
#include<stdio.h>

int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}

int main(void){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);

    int num = 0,i=min(a,b),ans;
    while(1){
        if(a%i==0 && b%i==0){
            num++;
            ans = i;
        }
        if(num == k){
            break;
        }
        i--;
    }

    printf("%d\n",ans);
    return 0;
}
