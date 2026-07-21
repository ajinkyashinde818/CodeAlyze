#include<stdio.h>

int main(void){
    long k;
    int n;
    scanf("%ld %d",&k,&n);
    long a[n];
    for(int i = 0;i < n;i++)scanf("%ld",&a[i]);
    long dif[n];
    for(int i = 0;i < n-1;i++)dif[i] = a[i+1] - a[i];
    dif[n-1] = a[0] + k - a[n-1];
    long maxdif = 0;
    for(int i = 0;i < n;i++)maxdif = (maxdif>dif[i]?maxdif:dif[i]);
    printf("%ld",k-maxdif);
    return 0;
}
