#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <random>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <tuple>
#include <math.h>
#include <set>
#include <map>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
using vc = vector<char> ;
using vvc = vector<vc> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;
using pll = pair<ll,ll> ;
#define all(v) v.begin(),v.end() 
const ll INF = 1e18 ;
const ll mod = 1e9+7 ;
const double pie = acos(-1); 
vll dx4 = {-1,0,1,0} ;
vll dy4 = {0,-1,0,1} ;
vll dx8 = {-1,0,1,1,1,0,-1,-1} ;
vll dy8 = {-1,-1,-1,0,1,1,1,0} ; 

void fix_cout(){cout << fixed << setprecision(20) ; }
ll gcd(ll a,ll b){if(b==0) return a ; return gcd(b,a%b) ; }
ll lcm(ll a,ll b){return a/gcd(a,b)*b ; }
void chmax(ll &a,ll b){if(a<b) a = b ; }
void chmin(ll &a,ll b){if(a>b) a = b ; }

vll solve1(vll &a,vll &b,int n){
	vll ans(n,0),sum(n+1,0) ;
	for(int i=1;i<=n;i++) sum[i] += sum[i-1]+a[i] ;
	priority_queue<pair<ll,pll>> pq ;
	queue<int> q ;
	for(int i=1;i<=n;i++) if(a[i]+b[i]>0) pq.emplace(b[i],pll(a[i]-b[i],i)) ;
	set<int> s ;
	s.insert(-1) ;
	s.insert(n) ;
	for(int i=0;i<n;i++) s.insert(i) ;
	while(!pq.empty()){
		int num = pq.top().second.second ;
		pq.pop() ;
		ll cnt = b[num] ;
		while(cnt){
			ll pos = *s.lower_bound(sum[num]) ;
			if(pos==n) break ;
			ans[pos] = num ;
			s.erase(pos) ;
			cnt-- ;
		}
		while(cnt){
			ll pos = *prev(s.lower_bound(sum[num-1])) ;
			if(pos==-1) break ;
			ans[pos] = num ;
			s.erase(pos) ;
			cnt-- ;
		}
		while(cnt){
			if(q.empty()){
				return ans ;
			}
			ll pos = q.front() ;
			q.pop() ;
			ans[pos] = num ;
			cnt-- ;
		}
		for(int i=0;i<a[num];i++){
			if(!s.count(sum[num-1]+i)) continue ;
			q.push(sum[num-1]+i) ;
			s.erase(sum[num-1]+i) ;
		}
		// for(int i=0;i<n;i++) cout << ans[i] << (i+1==n?"\n":" ") ;
	}
	return ans ;
}

vll solve2(vll &a,vll &b,int n){
	vll ans(n,0),sum(n+1,0) ;
	for(int i=1;i<=n;i++) sum[i] += sum[i-1]+a[i] ;
	priority_queue<pair<ll,pll>> pq ;
	queue<int> q ;
	for(int i=1;i<=n;i++) if(a[i]+b[i]>0) pq.emplace(a[i]-b[i],pll(b[i],i)) ;
	set<int> s ;
	s.insert(-1) ;
	s.insert(n) ;
	for(int i=0;i<n;i++) s.insert(i) ;
	while(!pq.empty()){
		int num = pq.top().second.second ;
		pq.pop() ;
		ll cnt = b[num] ;
		while(cnt){
			ll pos = *s.lower_bound(sum[num]) ;
			if(pos==n) break ;
			ans[pos] = num ;
			s.erase(pos) ;
			cnt-- ;
		}
		while(cnt){
			ll pos = *prev(s.lower_bound(sum[num-1])) ;
			if(pos==-1) break ;
			ans[pos] = num ;
			s.erase(pos) ;
			cnt-- ;
		}
		while(cnt){
			if(q.empty()){
				return ans ;
			}
			ll pos = q.front() ;
			q.pop() ;
			ans[pos] = num ;
			cnt-- ;
		}
		for(int i=0;i<a[num];i++){
			if(!s.count(sum[num-1]+i)) continue ;
			q.push(sum[num-1]+i) ;
			s.erase(sum[num-1]+i) ;
		}
		// for(int i=0;i<n;i++) cout << ans[i] << (i+1==n?"\n":" ") ;
	}
	return ans ;
}

int main(){
	ll n ; cin >> n ;
	vll a(n+1,0),b(n+1.0),sub(n) ;
	for(int i=0;i<n;i++){
		ll c ; cin >> c ;
		a[c]++ ;
		sub[i] = c ;
	}
	for(int i=0;i<n;i++){
		ll c ; cin >> c ;
		b[c]++ ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]+b[i]>n){
			cout << "No" << endl ;
			return 0 ;
		}
	}
	vll ans(n) ;
	auto check = [&](){
		bool ok = true ;
		for(int i=0;i<n;i++) ok &= (sub[i]!=ans[i]&&ans[i]!=0) ;
		if(ok){
			cout << "Yes" << endl ;
			for(int i=0;i<n;i++) cout << ans[i] << (i+1==n?"\n":" ") ;
			return true ;
		}
		return false ;
	} ;
	ans = solve1(a,b,n) ;
	if(check()) return 0 ;
	// else for(int i=0;i<n;i++) cout << ans[i] << (i+1==n?"\n":" ") ;
	ans = solve2(a,b,n) ;
	if(check()) return 0 ;
	// else for(int i=0;i<n;i++) cout << ans[i] << (i+1==n?"\n":" ") ;
	cout << "No" << endl ;
}
