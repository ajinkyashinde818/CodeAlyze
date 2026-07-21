#include<stdio.h>
int n,a[200000],r,t[200000],i;
long long k,q;
int main(){
    scanf("%d%lld",&n,&k);
    for(i=0;i<n;i++){scanf("%d",&a[i]);t[i]=-1;}
    r=1;
    i=0;
    while(t[r-1]==-1){
        t[r-1]=i++;
        r=a[r-1];
    }
    if(k<i)q=k;
    else q=(k-t[r-1])%(i-t[r-1])+t[r-1];
    for(i=0;i<n;i++)if(t[i]==q)break;
    printf("%d",i+1);
    return 0;
}
