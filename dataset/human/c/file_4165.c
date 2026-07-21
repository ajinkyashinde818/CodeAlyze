#include<stdio.h>

int main(){
    int a,b,k,i,temp[100];
    int c=1;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&k);
    for(i=1;i<=100;i++){
        if(a<i && b<i)break;
        if(a%i!=0)continue;
        if(b%i!=0)continue;
        temp[c++] = i;
    }
    printf("%d\n",temp[c-k]);
    return 0;
}
