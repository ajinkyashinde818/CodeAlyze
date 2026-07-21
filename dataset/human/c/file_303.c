#include <stdio.h>
long int abs2(long int a)
{
    if(a<0) return -a;
    return a;
}
long int sum(long int n, long int a[])
{
    long int i, sum=0;
    for(i=0;i<n;i++){
        if(a[i]<0) a[i]=a[i]*(-1);
        sum=sum+a[i];
    }
    return sum;
}
long int summin(long int n, long int a[], long int minidx)
{
    long int i, sum=0;
    for(i=0;i<n;i++){
        if(a[i]<0 && i!=minidx) a[i]=a[i]*(-1);
        else if(i==minidx && a[i]>0) a[i]=a[i]*(-1);
        sum=sum+a[i];
    }
    return sum;
}
int main(void)
{
    long int n, a[100000], i, ans, cntm=0, min=1000000001, minidx;
    scanf("%ld", &n);
    for(i=0;i<n;i++){
        scanf("%ld", &a[i]);
        if(abs2(a[i])<min){
            min=abs2(a[i]);
            minidx=i;
        }
    }

    for(i=0;i<n;i++){
        if(a[i]<=0) cntm++;
    }
    if(cntm%2==0) ans=sum(n, a);
    else ans=summin(n, a, minidx);
    printf("%ld\n", ans);
    return 0;
}
