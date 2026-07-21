#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

bool comp(ll L, ll R){
	return abs(L) < abs(R);
}

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll count=0;
	REP(i,n){
		cin >> a[i];
		if(a[i] < 0) count++;
	}
	sort(a.begin(),a.end(),comp);
	
	ll ans=0;
	REP(i,n){
		if(i==0){
			if(count%2){
				chmin(a[i], -1*a[i]);
			}else{
				chmax(a[i], -1*a[i]);
			}
		}else{
			chmax(a[i], -1*a[i]);
		}
		
		ans += a[i];
	}
	
	cout << ans << "\n";
	
	
	return 0;
}
