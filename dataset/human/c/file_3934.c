#include<stdio.h>

int main(){
    int a,b,k,c[100],i,j=0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&k);
    for(i=100;i>0;i--){
        if(a%i==0&&b%i==0){
            c[j]=i;
            j++;
        }
    }
    printf("%d",c[k-1]);
    return 0;
}
