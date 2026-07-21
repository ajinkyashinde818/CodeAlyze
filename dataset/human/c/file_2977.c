#include <stdio.h>
int a[100010];
int main(){
    int i,n;
    long long s=0,t=0,m;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
    m=(long long)n*(n+1)/2;
    if(s%m){puts("NO");return 0;}
    m=s/m;
    a[n+1]=a[1];
    for(i=1;i<=n;++i){
        s=a[i+1]-a[i];
        s+=m*(n-1);
        if(s%n||m<s/n){puts("NO");return 0;}
        t+=m-s/n;
    }
    if(t!=m)puts("NO");
    else puts("YES");
    return 0;
}
