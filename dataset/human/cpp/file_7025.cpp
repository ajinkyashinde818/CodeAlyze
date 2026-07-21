#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef pair<double,double> PD;
typedef priority_queue<P,vector<P>,greater<P> > P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd> > Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-6;

#define _GLIBCXX_DEBUG
#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end())

void Add(ll &a, ll b){
    a=(a+b)%mod;
    return;
}

void Pro(ll &a, ll b){
    a=(a*b)%mod;
    return;
}

vec Solve(){
    ll N; cin>>N;
    vec A(N), B(N), Count(N+1,0), CountB(N+1,0);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N) {Count[A[i]]++; Count[B[i]]++; CountB[B[i]]++;}
    ll Max_Count=-1, Max_i=-1;
    vec akan;
    akan.pb(-1);
    rep(i,N+1) if(Count[i]>N) return akan;
    vec ans(N,-1);
    priority_queue<P> Q;
    rep(i,N+1) if(CountB[i]) Q.push(mp(Count[i],i));
    while(!Q.empty()){
        ll x=Q.top().second;
        Q.pop();
        ll f=upper_bound(ALL(A),x)-A.begin();
        rep(i,CountB[x]){
            ll I=(f+N+i)%N;
            while(ans[I]>=0){
                f++; I=(f+N+i)%N;
            }
            ans[I]=x;
        }
    }
    return ans;

}

int main(){
    vec ANS=Solve();
    if(ANS[0]<0) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(auto e:ANS) cout<<e<<' ';
        cout<<endl;
    }
}
