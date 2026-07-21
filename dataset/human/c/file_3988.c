#include<stdio.h>
int main(void){
    int a,b,n,cnt,temp,i;
    scanf("%d %d %d",&a,&b,&n);
    cnt=0;
    if(a<b){
        temp=b;
        b=a;
        a=temp;
    }
    for(i=a;i!=0;i--){
        if(a%i==0&&b%i==0){
            cnt++;
            if(cnt==n){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
