#include<stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int a[n],b[n],c[n-1];
    for(int i=0;n>i;++i)
    scanf("%d",&a[i]);
    for(int i=0;n>i;++i)
    scanf("%d",&b[i]);
    for(int i=0;n-1>i;++i)
    scanf("%d",&c[i]);
    int sum=0;
    for(int i=0;n>i;++i)
    sum+=b[i];
    for(int i=0;n-1>i;++i){
        if(a[i]==a[i+1]-1)
        sum+=c[a[i]-1];
    }
    printf("%d",sum);
    return 0;
}
