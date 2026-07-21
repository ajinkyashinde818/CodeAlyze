#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

ll N,C;
vector<ll> x,v;
ll solve(){
    ll res = 0;
    cin >> N >> C;
    x.resize(N); v.resize(N);
    for(int i = 0; i < N;i++) cin >> x[i] >> v[i];
    
    vector<ll> cusum(N+1,0);
    vector<ll> rcusum(N+1,0);
    for(int i = 0; i <N;i++){
        cusum[i+1] = cusum[i] + v[i];
    }
    for(int i = 0; i < N;i++){
        cusum[i+1] -= x[i];
        res = max(res,cusum[i+1]);
    }
 //   cout << cusum << endl;
    
    reverse(x.begin(),x.end()); reverse(v.begin(),v.end());
    for(int i = 0; i < N;i++){
        rcusum[i+1] = rcusum[i] + v[i];
    }
    for(int i = 0; i < N;i++){
        rcusum[i+1] -= (C-x[i]);
        res = max(res,rcusum[i+1]);
    }
   // cout << rcusum << endl;
    
    vector<ll> check(N+1,0);
    for(int i = 1; i <= N;i++){
        check[i] = max(rcusum[i],check[i-1]);

    }
 //   cout << check << endl;
    reverse(x.begin(),x.end());
//    cout << res << endl;
    for(int i = 1; i < N; i++){
     //   cout << cusum[i] << " " << x[i-1] << " " << check[N-i] << endl;
     //   cout << cusum[i]-x[i-1]+check[N-i] << endl;
        res = max(res,cusum[i]-x[i-1]+check[N-i]);
    }
    
    check.assign(N+1,0);
    for(int i = 1; i <= N;i++){
        check[i] = max(cusum[i],check[i-1]);
    }
    reverse(x.begin(),x.end());
    for(int i = 1; i < N;i++){
        res = max(res,rcusum[i]-(C-x[i-1])+check[N-i]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
