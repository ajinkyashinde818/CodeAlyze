#include <bits/stdc++.h>
using namespace std;
 
typedef double db;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll MOD = 1e9+7;
const double PI  = 3.14159265358;
const double EPS = 1e-8;

#define INT_MX 2147483647
#define INF ((int)1e9)
#define LLINF ((ll)1e18)
#define F first
#define S second
#define MP(x,y) make_pair(x,y)
#define siz(v) ((int)v.size())
#define rs(n) resize(n)
#define ALL(v) v.begin(),v.end()
#define reset(v) memset((v),0,sizeof(v))
#define EB emplace_back
#define PB push_back
#define PF push_front
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,a,b) for(int i=(a);i<(b);i++) 
#define vec vector
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n, r;
	
	cin >> r >> n ;
	
	if(r >= 10)	cout << n ;
	else cout << n + 100 * (10 - r); 
	
	
}

int main(){
	int T = 1;
	
	while(T--){
		solve();
	}
}
