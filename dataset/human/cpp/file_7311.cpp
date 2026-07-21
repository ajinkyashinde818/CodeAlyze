#include <cstdio>
#include <iostream>
using namespace std;
int n,a[200002];
int main(){
   scanf("%d",&n);
   long long sum=0;
    for(int i=1;i<=n;++i){
       scanf("%d",&a[i]);
       sum+=a[i];
    }
   long long s=0,ans=200000000000000LL;
    for(int i=1;i<n;++i){
        s+=a[i];
        ans=min(ans,abs(sum-s-s));
   }
    cout<<ans;
}
