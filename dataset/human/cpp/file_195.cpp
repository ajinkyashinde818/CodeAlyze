#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

const int mod=1000000007;


int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans=0;
    int x=n/r;
    int y=n/g;
    rep(i,x+2){
        rep(j,y+2){
            if(i*r+j*g<=n&&(n-i*r-j*g)%b==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
