#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)



int main(){
    ll n;cin>>n;
    ll a[n];rep(i,n)cin>>a[i];
    ll absmin=1000000009;
    ll minusctr=0;
    ll abssum=0;
    bool zfinder=0;
    rep(i,n){
        if(a[i]<0)minusctr++;
        else if(a[i]==0){
            zfinder=1;
        }
        chmin(absmin,llabs(a[i]));
        abssum+=llabs(a[i]);
    }
    if(zfinder)cout<<abssum<<endl;
    else if(minusctr%2==0)cout<<abssum<<endl;
    else cout<<abssum-(2*absmin)<<endl;
}
