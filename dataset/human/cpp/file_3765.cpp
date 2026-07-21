#include <iostream>
#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
#include <queue>
//#include <deque>
//#include <bitset>
#include <math.h>
using namespace std ;
using ll = long long ;
using ld = long double ;
using vll = vector<ll> ;
using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1000000007 ;
//long double pie = acos(-1) ;
//ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
//ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
void fix_cout(){cout << fixed << setprecision(20) ;}

template<class F,class S,class T>
struct triple{
	F first ;
	S second ;
	T third ;
	triple(F f,S s,T t){
		first = f ;
		second = s ;
		third = t ;
	}
	triple(){}

	bool operator<(const triple<F,S,T> &right) const{
		if(first!=right.first) return first<right.first ;
		else if(second!=right.second) return second<right.second ;
		else return third<right.third ;
	}
	bool operator>(const triple<F,S,T> &right) const{
		return right<*this ;
	}
	bool operator<=(const triple<F,S,T> &right) const{
		return !(*this>right) ;
	}
	bool operator>=(const triple<F,S,T> &right) const{
		return !(*this<right) ;
	}
};

int main(){
	auto dis = [](ll a,ll b,ll c,ll d){
		return sqrt((a-c)*(a-c)+(b-d)*(b-d)) ;
	} ;

	fix_cout() ;
	ll sx,sy,gx,gy ;
	cin >> sx >> sy >> gx >> gy ;
	ll n ; cin >> n ;
	vector<triple<ll,ll,ll>> c(n+2) ;
	c.at(0).first = sx ; c.at(0).second = sy ; c.at(0).third = 0 ;
	for(int i=1;i<=n;i++) cin >> c.at(i).first >> c.at(i).second >> c.at(i).third ;
	c.at(n+1).first = gx ; c.at(n+1).second = gy ; c.at(n+1).third = 0 ;
	vector<vector<ld>> d(n+2,vector<ld>(n+2)) ;
	for(int i=0;i<n+2;i++){
		for(int j=0;j<n+2;j++){
			if(i==j) d.at(i).at(j) = 0 ;
			else{
				d.at(i).at(j) = max(0.0,dis(c.at(i).first,c.at(i).second,c.at(j).first,c.at(j).second)-c.at(i).third-c.at(j).third) ;
			}
		}
	}
	vector<ld> cnt(n+2,100000000000000.0) ;
	priority_queue<triple<ld,ll,ll>,vector<triple<ld,ll,ll>>,greater<triple<ld,ll,ll>>> pq ;
	cnt.at(0) = 0 ;
	for(int i=1;i<n+2;i++) pq.emplace(d.at(0).at(i),0,i) ;
	vll use(n+2,0) ;
	while(!pq.empty()){
		triple<ld,ll,ll> e = pq.top() ;
		pq.pop() ;
		if(use.at(e.third)) continue ;
//		cout << e.second << " " << e.third << " " << e.first << endl ;
		use.at(e.third) = 1 ;
		cnt.at(e.third) = e.first ;
		for(int i=0;i<n+2;i++) if(i!=e.third) pq.emplace(d.at(e.third).at(i)+cnt.at(e.third),e.third,i) ;
	}
	cout << cnt.at(n+1) << endl ;
//	for(auto i:cnt) cout << i << endl ;
}
