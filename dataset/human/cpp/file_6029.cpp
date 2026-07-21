#include<stdio.h>
#include<algorithm>
typedef long long int llint;
using namespace std;
int main(){
    llint n,c;
    scanf("%lld%lld",&n,&c);
    llint x[n],v[n];
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&x[i],&v[i]);
    llint r[n],l[n];
    llint r2[n],l2[n];
    r[0]=max(v[0]-x[0],0ll);
    r2[0]=max(v[0]-2*x[0],0ll);
    llint cal=v[0];
    for(int i=1;i<n;i++){
        cal=cal+v[i];
        r[i]=max(r[i-1],cal-x[i]);
        r2[i]=max(r2[i-1],cal-2*x[i]);
    }
    l[n-1]=max(v[n-1]-c+x[n-1],0ll);
    l2[n-1]=max(v[n-1]-2*c+2*x[n-1],0ll);
    cal=v[n-1];
    for(int i=n-2;i>=0;i--){
        cal=cal+v[i];
        l[i]=max(l[i+1],cal-c+x[i]);
        l2[i]=max(l2[i+1],cal-2*c+2*x[i]);
    }
    llint ans=0;
    ans=max(ans,r[n-1]);
    ans=max(ans,l[0]);
    for(int i=0;i<n-1;i++){
        ans=max(ans,l2[i+1]+r[i]);
        ans=max(ans,l[i+1]+r2[i]);
    }
    printf("%lld\n",ans);
}
