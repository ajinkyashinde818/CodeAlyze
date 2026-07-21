#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef pair<ld,ll> dlP;

#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ld LINF=101001001001001.0;
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
ll n;
ll x[1010],y[1010],r[1010];
vector<pair<ll,ld>> to[1010];
vector<ld> d(1010);
void Dijkstra(){
    rep(i,1010)d[i]=LINF;
    d[n]=0;
    priority_queue<dlP,vector<dlP>,greater<dlP>> pq;
    pq.push({0.0,n});
    while(pq.size()){
        ll nowp=pq.top().se;
        ld nowd=pq.top().fi;
        pq.pop();
        if(nowd>d[nowp])continue;
        for(auto nxt: to[nowp]){
            ll nxtp=nxt.fi;
            ld nxtd=nxt.se+nowd;
            //cout<<nxtp<<" "<<nxtd<<endl;
            if(chmin(d[nxtp],nxtd)){
                pq.push({nxtd,nxtp});
            }
        }
    }
    return;
}
ld f(int s,int t){
    ll dx=abs(x[t]-x[s]);
    ll dy=abs(y[t]-y[s]);
    ld res=sqrt(ld(dx*dx)+ld(dy*dy));
    if(s!=n||s!=n+1)res-=(ld)r[s];
    if(t!=n||t!=n+1)res-=(ld)r[t];
    res=max(res,(ld)0.0);
    return res;
}
int main(){
    ll xs,ys,xt,yt;cin>>xs>>ys>>xt>>yt;
    cin>>n;
    rep(i,n)cin>>x[i]>>y[i]>>r[i];
    x[n]=xs;y[n]=ys;
    x[n+1]=xt;y[n+1]=yt;
    rep(i,n+2){
        for(int j=i+1;j<n+2;j++){
            to[i].pb({j,f(i,j)});
            to[j].pb({i,f(i,j)});
        }
    }
    Dijkstra();
    ld ans=d[n+1];
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
    return 0;
}
