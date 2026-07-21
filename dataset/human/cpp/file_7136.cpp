#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

//#define int long long
//using ll = boost::multiprecision::cpp_int;
using ll = long long;
//const int INF = 2147483647;
const ll INF = 9223372036854775807LL;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
#ifdef LOCAL_ENV
	#define debug(var) std::cout<<#var" = "<<var<<std::endl
#else
	#define debug(var)
#endif
#define p(var)  std::cout<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for(int i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(int i=1, i##_length=(n); i<=i##_length; ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
inline bool isnatural(double a) { return a>=0 && ceil(a)==floor(a); }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2>inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2>inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	for (int i = 0, len = v.size(); i < len; ++i){
		s << v[i]; if (i < len - 1) s << "\t";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
	for (int i = 0, len = vv.size(); i < len; ++i){
		s << vv[i] << endl;
	}
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s, const map<T1, T2>& m) {
	s << "{" << endl;
	for (typeof(m.begin()) itr = m.begin(); itr != m.end(); ++itr){
		s << "\t" << (*itr).first << " : " << (*itr).second << endl;
	}
	s << "}" << endl;
	return s;
}

/*-----8<-----8<-----*/



signed main() {
	ll N;
	cin >> N;

	vector<ll> a(N,0);
	rep(i,N){
		cin >> a[i];
	}

	ll sum=accumulate(all(a),0LL);
	vector<ll> rui(N+1,0);
	ll minval=INF;
	rep(i,N)rui[i+1]=rui[i]+a[i];

	repeq(i,N-1){
		ll t=abs((sum-rui[i])-rui[i]);
		chmin(minval,t);
	}

	p(minval);

	return 0;
}
