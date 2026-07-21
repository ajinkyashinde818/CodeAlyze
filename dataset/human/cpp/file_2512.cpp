#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

int main(){
    ll N; cin>>N;
    ll MIN=INF;
    ll SUM=0;
    ll fu=0;
    rep(i,N){
        ll A; cin>>A;
        if(A<0) fu++;
        SUM+=abs(A);
        MIN=min(MIN,abs(A));
    }
    if(fu%2) SUM-=(MIN*2);
    cout<<SUM<<endl;
}
