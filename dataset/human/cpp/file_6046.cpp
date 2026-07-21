#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll c;
    cin >> c;
    ll x[n];
    ll xinv[n];
    ll v[n];
    rep(i,n){
        cin >> x[i] >> v[i];
        xinv[i]=c-x[i];
    }
    ll mx[n];
    ll mxinv[n];
    ll xn[n];
    ll xninv[n];
  	ll lz=0;
    rep(i,n){
        if(i==0){
            xn[i]=v[i];
            mx[i]=max(lz,v[i]-2*x[i]);
        }
        else{
            xn[i]=xn[i-1]+v[i];
            mx[i]=max(mx[i-1],xn[i]-2*x[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            xninv[i]=v[i];
            mxinv[i]=max(lz,v[i]-xinv[i]);
        }
        else{
            xninv[i]=xninv[i+1]+v[i];
            mxinv[i]=max(mxinv[i+1],xninv[i]-xinv[i]);
        }
    }
    ll sum=0;
    rep(i,n-1)chmax(sum,mx[i]+mxinv[i+1]);
  	chmax(sum,mxinv[0]);
    chmax(sum,mx[n-1]);
    rep(i,n){
        if(i==0){
            mx[i]=max(lz,v[i]-x[i]);
        }
        else{
            mx[i]=max(mx[i-1],xn[i]-x[i]);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            mxinv[i]=max(lz,v[i]-2*xinv[i]);
        }
        else{
            mxinv[i]=max(mxinv[i+1],xninv[i]-2*xinv[i]);
        }
    }
    rep(i,n-1)chmax(sum,mx[i]+mxinv[i+1]);
  	chmax(sum,mxinv[0]);
    chmax(sum,mx[n-1]);
    cout << sum;
}
