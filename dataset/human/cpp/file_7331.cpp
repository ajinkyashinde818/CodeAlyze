#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i=0;i<N;++i)cin>>A[i];
    ll sum=0;
    for(ll i=0;i<N;++i)sum+=A[i];
    ll ans=llabs(sum-2*A[0]);
    ll unt=A[0];
    for(ll i=1;i<N-1;++i){
        unt+=A[i];
        chmin(ans,llabs(sum-2*unt));
    }
    prt(ans)

    return 0;
}
