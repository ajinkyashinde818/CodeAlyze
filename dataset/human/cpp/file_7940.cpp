#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    long long sum=0;
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    long long now=a[0],ans=abs(sum-now*2);
    for(int i=1;i<n-1;i++){
        now+=a[i];
        ans=min(ans,abs(sum-now*2));
    }
    printf("%lld\n",ans);
}
