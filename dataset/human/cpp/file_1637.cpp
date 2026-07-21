#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
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

void solve(){
    ll N; cin >> N;
    bool ok = false;
    ll L = -1;
    for(ll a = 1; a <= N+10; a++){
        if(a*(a+1)==2*N){
            ok = true;
            L = a;
            break;
        }
    }
    if(!ok){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        cout << L+1 << endl;
        vector<vector<ll>> Ans(L+1,vector<ll>(L));
        ll key = 1;
        for(int i = 0; i < L;i++){
            for(int j = 0; j < L;j++){
                if(Ans[i][j]!=0) continue;
                
                for(int k = 0; j+k < L;k++){
                    Ans[i][j+k] = key;
                    Ans[i+k+1][j] = key;
                    key++;
                }
                break;
            }
        }
        
        for(int i = 0; i <= L;i++){
            cout << L << " " << Ans[i] << endl;
        }
    }
    
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
