#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
const int MAXN=2e5+10;
const ll MOD=17;
ll _gcd(ll a,ll b){if(b==0)return a;return _gcd(b,a%b);}
ll gcd(ll a,ll b){a=abs(a),b=abs(b);if(a<b)swap(a,b);return _gcd(a,b);}
ll qpow(ll a,ll n){ll rt=1;while(n){if(n&1)rt=(rt*a)%MOD;a=a*a%MOD;n>>=1;}return rt;}
ll factor[MAXN];
void cal_factor(){factor[0]=1;for(int u=1;u<MAXN;u++){factor[u]=(factor[u-1]*u)%MOD;}}
ll C(ll n,ll k){return factor[n]*qpow(factor[n-k],MOD-2)%MOD*qpow(factor[k],MOD-2)%MOD;}
int n;
int A[MAXN];
int B[MAXN];
void solve(){
    cin>>n;
    for(int u=0;u<n;u++)cin>>A[u];
    for(int u=0;u<n;u++)cin>>B[u];
    sort(B,B+n,greater<int>());
    int c=-1;
    int l=0,r=-1;
    for(int u=0;u<n;u++){
        if(A[u]==B[u]){
            c=A[u];
            l=u;
            break;
        }
    }
    for(int u=n-1;u>=0;u--){
        if(A[u]==B[u]){
            r=u;
            break;
        }
    }
    for(int u=0;u<n;u++){
        if(l>r)break;
        if(A[u]!=c&&B[u]!=c){
            swap(B[u],B[l]);
            l++;
        }
    }
    if(l<=r){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    for(int u=0;u<n;u++)cout<<B[u]<<" ";
}
// #define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
