#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

ld dist(ld x1,ld y1,ld x2,ld y2){
    return (ld)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ld xs;
    cin >> xs;
    ld ys;
    cin >> ys;
    ld xt;
    cin >> xt;
    ld yt;
    cin >> yt;
    ld N;
    cin >> N;
    vector<ld> x(N+2,0.0);
    vector<ld> y(N+2,0.0);
    vector<ld> r(N+2,0.0);
    x[0]=xs;y[0]=ys;
    x[N+1]=xt;y[N+1]=yt;
    for(ll i=1;i<=N;++i)cin>>x[i]>>y[i]>>r[i];
    vector<vector<pair<ll,ld>>> G(N+2, vector<pair<ll,ld>>(0));
    for(ll i=0;i<N+2;++i){
        for(ll j=i+1;j<N+2;++j){
            ld h=dist(x[i],y[i],x[j],y[j])-r[i]-r[j];
            if(h>0.0){
                G[i].emplace_back(pair<ll,ld>(j,h));
                G[j].emplace_back(pair<ll,ld>(i,h));
            }
            else {
                G[i].emplace_back(pair<ll,ld>(j,0.0));
                G[j].emplace_back(pair<ll,ld>(i,0.0));
            }
        }
    }

    //ダイクストラ法
    //vvl GにP(to,cost)って感じで隣接リストにしておく
    //計算量|E|log|V|
    //頂点数N
    priority_queue<pair<ld,ll>, vector<pair<ld,ll>>, greater<pair<ld,ll>>> pq;
    vector<ld> d(N+2,INF);
    d[0]=0.0;
    pq.emplace(P(0.0,0));
    while(!pq.empty()){
        P w=pq.top();
        pq.pop();
        ld Y=w.first;
        ll z=w.second;
        if(Y>d[z])continue;
        for(auto p: G[z]){
            if(d[p.first]>d[z]+p.second){
                d[p.first]=d[z]+p.second;
                pq.emplace(P(d[p.first],p.first));
            }
        }
    }

    cout << fixed << setprecision(10);


    prt(d[N+1])

    

    return 0;
}
