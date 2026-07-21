#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=2e5+9;
int n,f[N];
bool vis[N];
int a[N];
string s;
int ans;
inline void add(int x,int y){for(;x<N;x+=(x&-x))f[x]+=y;}
inline int query(int x){int ans=0;while(x)ans+=f[x],x-=(x&-x);return ans;}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;cin>>s;s=" "+s;
    int cnt=0;
    //for(int i=1;i<=2*n;i++)cout<<s[i];
    //cout<<endl;
    for(int i=1;i<=2*n;i++)if(i%2){if(s[i]=='W')a[++cnt]=i;}else if(s[i]=='B')a[++cnt]=i;
  //  for(int i=1;i<=cnt;i++)cout<<a[i]<<endl;
    if(cnt!=n)cout<<0<<endl;
    else{
        int tt=0;
        ll ans=1;
        for(int i=1;i<=n;i++)ans=1ll*ans*(a[i]-tt-1)%mod,tt+=2;
        for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
        cout<<ans<<endl;
    }
    return 0;
}
