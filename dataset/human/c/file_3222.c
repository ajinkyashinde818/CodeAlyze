#include<stdio.h>
int main(void){
    int k,n;
    scanf("%d%d",&k,&n);
    int a[n];
    for(int i=0;n>i;++i){
        scanf("%d",&a[i]);
    }
  /*入力*/
    int b[n-1];
    for(int i=0;n-1>i;++i){
        b[i]=a[i+1]-a[i];
    }
    int max=b[0];
    for(int i=1;n-1>i;++i){
        max=max>b[i]?max:b[i];
    }
    int p=k-a[n-1]+a[0];
    max=max>p?max:p;
    printf("%d",k-max);
    return 0;
}
