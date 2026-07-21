#include<stdio.h>

int main(void){
    int a,b,k,i,cnt;
    cnt = 0;

    scanf("%d %d %d",&a,&b,&k);

    for(i=100; i>=1; i--){
       if ( (a % i == 0) && (b % i == 0) )
       cnt++;
       if(cnt == k)
       break;
    }

    printf("%d\n",i);

    return 0;
}
