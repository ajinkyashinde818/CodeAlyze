#include <bits/stdc++.h>
using namespace std;
const int maxn=100007;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
typedef  long long ll;
int sum1[maxn],sum2[maxn],a[maxn];
int main(){
    int ans=0;
    int n;cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) if(a[i]<0) ans++;
    if(ans%2==0){
        ll tot=0;
        for(int i=1;i<=n;i++) tot+=abs(a[i]);cout<<tot;
    }
    else{
        ll mn=-(1LL<<60),tot=0;
        for(int i=1;i<=n;i++) {tot+=abs(a[i]);mn=max(mn,-1LL*abs(a[i]));}
        tot+=2*mn;cout<<tot;
    }

    return 0;
}
