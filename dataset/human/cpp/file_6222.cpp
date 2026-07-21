#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=(b-1);i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

ll d1[100100];
ll d2[100100];
ll d3[100100];
ll d4[100100];
ll d5[100100];
ll d6[100100];

int main() {
	ll n,c;
	cin>>n>>c;
	vector<ll> vx;
	vector<ll> vv;
	rep(i,0,n){
		ll a,b;
		cin>>a>>b;
		vx.pb(a);
		vv.pb(b);
	}
	ll mx = 0;
	ll a = 0;
	rep(i,0,vx.sz){
		a += vv[i];
		d1[i] = a-vx[i];
		mx = max(mx,d1[i]);
	}
	ll b = 0;
	per(i,0,vx.sz){
		b += vv[i];
		d2[i] = b - (c-vx[i]);
		mx = max(mx,d2[i]);
	}
	rep(i,0,vx.sz){
		d3[i] = max(0LL,d1[i]-vx[i]);
		if(i>0){
			if(d3[i]<d3[i-1]){
				d3[i] = d3[i-1];
			}
		}
	}
	per(i,0,vx.sz){
		d4[i] = max(0LL,d2[i]-(c-vx[i]));
		if(i<vx.sz-1){
			if(d4[i]<d4[i+1]){
				d4[i] = d4[i+1];
			}
		}
	}
	rep(i,0,vx.sz){
		d5[i] = max(0LL,d1[i]);
		if(i>0){
			if(d5[i]<d5[i-1]){
				d5[i] = d5[i-1];
			}
		}
	}
	per(i,0,vx.sz){
		d6[i] = max(0LL,d2[i]);
		if(i<vx.sz-1){
			if(d6[i]<d6[i+1]){
				d6[i] = d6[i+1];
			}
		}
	}
	rep(i,0,vx.sz-1){
		mx = max(mx,d3[i]+d6[i+1]);
	}
	rep(i,1,vx.sz){
		mx = max(mx,d4[i]+d5[i-1]);
	}
	cout << mx << endl;
	return 0;
}
