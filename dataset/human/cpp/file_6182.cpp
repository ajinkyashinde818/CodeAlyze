#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;cin>>n;ll c;cin>>c;
    vector<ll> x(n),v(n);
    for(int i=0;i<n;i++) cin>>x[i]>>v[i];
    vector<ll> su(n,0),rev(n,0);
    su[0]=v[0],rev[n-1]=v[n-1];
    for(int i=1;i<n;i++) su[i]=su[i-1]+v[i];
    for(int i=n-2;i>=0;i--) rev[i]=rev[i+1]+v[i];
    vector<ll> su2(n,0),rev2(n,0);
    su2[0]=su[0]-x[0];rev2[n-1]=rev[n-1]-(c-x[n-1]);
    for(int i=1;i<n;i++) su2[i]=max(su2[i-1],su[i]-x[i]);
    for(int i=n-2;i>=0;i--) rev2[i]=max(rev2[i+1],rev[i]-(c-x[i]));
    ll res=0;
    for(int i=0;i<n-1;i++){
        ll tmp=0;
        tmp=su[i]-2*x[i]+rev2[i+1];
        res=max(res,tmp);
        res=max(res,su[i]-x[i]);
    }
    res=max(res,su[n-1]-x[n-1]);
    for(int i=n-1;i>=1;i--){
        ll tmp=0;
        tmp=rev[i]-2*(c-x[i])+su2[i-1];
        res=max(res,tmp);
        res=max(res,rev[i]-(c-x[i]));
    }
    res=max(res,rev[0]-(c-x[0]));
    cout<<res<<endl;
}
