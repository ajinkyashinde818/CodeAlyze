#include "bits/stdc++.h"
using namespace std;
using     ll=long long;
using    vll=vector<   ll>;
using   vvll=vector<  vll>;
using  vvvll=vector< vvll>;
using vvvvll=vector<vvvll>;
using     dd=double;
using    vdd=vector<   dd>;
using   vvdd=vector<  vdd>;
using  vvvdd=vector< vvdd>;
using vvvvdd=vector<vvvdd>;
constexpr ll INF = 1LL << 60;
struct Fast{ Fast(){ cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(numeric_limits<double>::max_digits10); } } fast;
#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define rep(i, S, E)  for (ll i = (S); i <= (E); i++)
#define dep(i, E, S)  for (ll i = (E); i >= (S); i--)
#define each(e, v) for (auto&& e : v)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmax(m,v[i]); return m; }
template<class T> inline T MinE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmin(m,v[i]); return m; }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v,0,(ll)v.size()-1); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v,0,(ll)v.size()-1); }
template<class T> inline T Sum(vector<T> &v,ll S,ll E){ T s=T(); rep(i,S,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v) { return Sum(v,0,v.size()-1); }
template<class T> inline ll sz(T &v){ return (ll)v.size(); }
inline ll CEIL(ll a,ll b){ return (a<0) ? -(-a/b) : (a+b-1)/b; }
inline ll FLOOR(ll a,ll b){ return -CEIL(-a,b); }

//vector用テンプレート
template<class T> inline vector<T>& operator+=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]+=b[i];  return a; }
template<class T> inline vector<T>& operator-=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]-=b[i];  return a; }
template<class T> inline vector<T>& operator*=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]*=b[i];  return a; }
template<class T> inline vector<T>& operator/=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]/=b[i];  return a; }
template<class T> inline vector<T>& operator%=(vector<T> &a,const vector<T> &b){ for (ll i=0; i<(ll)a.size(); i++) a[i]%=b[i];  return a; }
template<class T,class S> inline vector<T>& operator+=(vector<T> &a,S b){ for (T &e: a) e+=b;  return a; }
template<class T,class S> inline vector<T>& operator-=(vector<T> &a,S b){ for (T &e: a) e-=b;  return a; }
template<class T,class S> inline vector<T>& operator*=(vector<T> &a,S b){ for (T &e: a) e*=b;  return a; }
template<class T,class S> inline vector<T>& operator/=(vector<T> &a,S b){ for (T &e: a) e/=b;  return a; }
template<class T,class S> inline vector<T>& operator%=(vector<T> &a,S b){ for (T &e: a) e%=b;  return a; }
template<class T,class S> inline vector<T> operator+(const vector<T> &a,S b){ vector<T> c=a; return c+=b; }
template<class T,class S> inline vector<T> operator-(const vector<T> &a,S b){ vector<T> c=a; return c-=b; }
template<class T,class S> inline vector<T> operator*(const vector<T> &a,S b){ vector<T> c=a; return c*=b; }
template<class T,class S> inline vector<T> operator/(const vector<T> &a,S b){ vector<T> c=a; return c/=b; }
template<class T,class S> inline vector<T> operator%(const vector<T> &a,S b){ vector<T> c=a; return c%=b; }
template<class T,class S> inline vector<T> operator-(S b,const vector<T> &a){ vector<T> c=-a; return c+=b; }
template<class T> inline vector<T> operator-(const vector<T> &a){ vector<T> c=a; return c*=(-1); }
template<class T> inline ostream &operator<<(ostream &os,const vector<T> &a){ for (ll i=0; i<(ll)a.size(); i++) os<<(i>0?" ":"")<<a[i];  return os; }

//pair用テンプレート
using   pll=pair<ll,ll>;
using  vpll=vector< pll>;
using vvpll=vector<vpll>;
template<class T,class S> inline pair<T,S>& operator+=(pair<T,S> &a,const pair<T,S> &b){ a.first+=b.first; a.second+=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator-=(pair<T,S> &a,const pair<T,S> &b){ a.first-=b.first; a.second-=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator*=(pair<T,S> &a,const pair<T,S> &b){ a.first*=b.first; a.second*=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator/=(pair<T,S> &a,const pair<T,S> &b){ a.first/=b.first; a.second/=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator%=(pair<T,S> &a,const pair<T,S> &b){ a.first%=b.first; a.second%=b.second; return a; }
template<class T,class S,class R> inline pair<T,S>& operator+=(pair<T,S> &a,R b){ a.first+=b; a.second+=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator-=(pair<T,S> &a,R b){ a.first-=b; a.second-=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator*=(pair<T,S> &a,R b){ a.first*=b; a.second*=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator/=(pair<T,S> &a,R b){ a.first/=b; a.second/=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator%=(pair<T,S> &a,R b){ a.first%=b; a.second%=b; return a; }
template<class T,class S,class R> inline pair<T,S> operator+(const pair<T,S> &a,R b){ pair<T,S> c=a; return c+=b; }
template<class T,class S,class R> inline pair<T,S> operator-(const pair<T,S> &a,R b){ pair<T,S> c=a; return c-=b; }
template<class T,class S,class R> inline pair<T,S> operator*(const pair<T,S> &a,R b){ pair<T,S> c=a; return c*=b; }
template<class T,class S,class R> inline pair<T,S> operator/(const pair<T,S> &a,R b){ pair<T,S> c=a; return c/=b; }
template<class T,class S,class R> inline pair<T,S> operator%(const pair<T,S> &a,R b){ pair<T,S> c=a; return c%=b; }
template<class T,class S,class R> inline pair<T,S> operator-(R b,const pair<T,S> &a){ pair<T,S> c=-a; return c+=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a){ pair<T,S> c=a; return c*=(-1); }
template<class T,class S> inline ostream &operator<<(ostream &os,const pair<T,S> &a){ return os << a.first << ' ' << a.second; }


template<ll MOD> struct mll_{
	ll val;
	mll_(ll v = 0): val(v % MOD){ if (val < 0) val += MOD; }
	mll_ operator - () const { return -val; }
	mll_ operator + (const mll_ &b) const { return val + b.val; }
	mll_ operator - (const mll_ &b) const { return val - b.val; }
	mll_ operator * (const mll_ &b) const { return val * b.val; }
	mll_ operator / (const mll_ &b) const { return mll_(*this) /= b; }
	mll_ operator + (ll b) const { return *this + mll_(b); }
	mll_ operator - (ll b) const { return *this - mll_(b); }
	mll_ operator * (ll b) const { return *this * mll_(b); }
	friend mll_ operator + (ll a,const mll_ &b) { return b + a; }
	friend mll_ operator - (ll a,const mll_ &b) { return -b + a; }
	friend mll_ operator * (ll a,const mll_ &b) { return b * a; }
	friend mll_ operator / (ll a,const mll_ &b) { return mll_(a)/b; }
	mll_ &operator += (const mll_ &b) { val=(val+b.val)%MOD; return *this; }
	mll_ &operator -= (const mll_ &b) { val=(val+MOD-b.val)%MOD; return *this; }
	mll_ &operator *= (const mll_ &b) { val=(val*b.val)%MOD; return *this; }
	mll_ &operator /= (const mll_ &b) {
		ll c=b.val,d=MOD,u=1,v=0;
		while (d){
			ll t = c / d;
			c -= t * d; swap(c,d);
			u -= t * v; swap(u,v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll_ &operator += (ll b) { return *this += mll_(b); }
	mll_ &operator -= (ll b) { return *this -= mll_(b); }
	mll_ &operator *= (ll b) { return *this *= mll_(b); }
	mll_ &operator /= (ll b) { return *this /= mll_(b); }
	bool operator == (const mll_ &b) { return val == b.val; }
	bool operator != (const mll_ &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll_(b); }
	bool operator != (ll b) { return *this != mll_(b); }
	friend bool operator == (ll a,const mll_ &b) { return mll_(a) == b.val; }
	friend bool operator != (ll a,const mll_ &b) { return mll_(a) != b.val; }
	friend ostream &operator << (ostream &os,const mll_ &a) { return os << a.val; }
	friend istream &operator >> (istream &is,mll_ &a) { return is >> a.val; }
	static mll_ Combination(ll a,ll b){
		chmin(b,a-b);
		if (b<0) return mll_(0);
		mll_ c = 1;
		rep(i,0,b-1) c *= a-i;
		rep(i,0,b-1) c /= i+1;
		return c;
	}
};
using mll = mll_<1000000007LL>;
using vmll    = std::vector<mll>;
using vvmll   = std::vector<vmll>;
using vvvmll  = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;


template<class T> inline T POW(T a,ll n){ T r=1; for (; n>0; n>>=1,a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a,ll n){ return POW((ll)a,n); }

#if defined(_DEBUG)
ll dumpW = 5;
template<class T> void dump(vector<T> &v){
	rep(i,0,sz(v)-1) { cerr << ((i==0)?"[":" ") << setw(dumpW) << v[i]; }  cerr << "]";
}
void dump(vll &v){
	rep(i,0,sz(v)-1) {
		cerr << ((i==0)?"[":" ") << setw(dumpW);
		if (v[i] == INF) cerr << "INF";
		else if (v[i] == -INF) cerr << "-INF";
		else                   cerr << v[i];
	}  cerr << "]";
}
template<class T> void dump(vector<vector<T>> &v){
	ll N=(ll)v.size();  string d[2][2]={{" ", "["},  {"\n", "]\n"}};
	rep(i,0,N-1) { cerr << d[0][i==0];  dump(v[i]);  cerr << d[1][i==N-1]; }
}
template<class T> void dump(vector<vector<vector<T>>> &v){
	ll N=(ll)v.size();  string d[2]={"  <", "[ <"};
	rep(i,0,N-1) { cerr << d[i==0] << i << ">\n"; dump(v[i]); }  cerr << "]\n";
}
template<class T> void dump(vector<vector<vector<vector<T>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ---<", "[ ---<"};
	rep(i,0,N-1) { cerr << d[i==0] << i << ">---\n"; dump(v[i]); }  cerr << "]\n";
}
template<class T> void dump(vector<vector<vector<vector<vector<T>>>>> &v){
	ll N=(ll)v.size();  string d[2]={"  ======<", "[ ======<"};
	rep(i,0,N-1) { cerr << d[i==0] << i << ">======\n"; dump(v[i]); }  cerr << "]\n";
}
template<class T,class S> void dump(map<T,S> &m){
	for (auto e: m) cout << e.first << " : " << e.second << '\n';
}
#else
template<class T> void dump(T &v){}
#endif

void solve()
{
	ll n;  cin >> n;
	vector<ll> a(n);  rep(i,0,n-1){ ll a_; cin>>a_; a[i]=a_; }
	deque<ll> b(n);  rep(i,0,n-1){ ll b_; cin>>b_; b[i]=b_; }

	vll cnta(n+1);
	each(e,a) cnta[e]++;
	vll cntb(n+1);
	each(e,b) cntb[e]++;
	vll cnt0=cnta+cntb;

	vpll buf;
	rep(i,1,n){
		ll nm=cnt0[i];
		if (nm>=1){
			buf.emplace_back(nm,i);
		}
	}
	sort(RALL(buf));
	if(buf[0].first>n){
		cout << "No" << '\n'; return;
	}

	vll table2idx(n+1,-1);

	rep(idx,0,sz(buf)-1){
		ll no=buf[idx].second;
		table2idx[no]=idx;
	}

	map<ll,vll> mp;
	rep(i,0,n-1){
		ll no=a[i];
		ll idx=table2idx[no];
		mp[idx].push_back(i);
	}

	vll ans(n);

	rep(idx,0,sz(buf)-1){
		ll no=buf[idx].second;

		auto it=mp.upper_bound(idx);
		if (it==mp.end()){ it=mp.begin(); }
		
		while (true){
			vll &vl=it->second;
			while (true){
				if (cntb[no]==0)break;
				if (vl.empty()) break;

				ll loc=vl.back(); vl.pop_back();
				ans[loc]=no;
				cntb[no]--;
			}
			if (vl.empty()){
				auto itt=it;
				it++;
				if (it==mp.end()){it=mp.begin();}
				mp.erase(itt);
			}

			if (cntb[no]==0)break;
		}

	}
	cout << "Yes" << '\n';
	cout << ans << '\n';

#if 0
	vpll cnt0(n);
	rep(i,0,n-1){
		cnt0[i].first=cnta[i]+cntb[i];
		cnt0[i].second=i;
	}
	sort(RALL(cnt0));

	if (cnt0[0].first>n){
		cout << "No" << '\n'; return;
	}

	vll ans(n);
	ll i=n-1;
	while (!b.empty()){
		ll v=b.front();
		if (v==a[i])break;

		ans[i]=v+1;
		b.pop_front();
		i--;
	}
	i=0;
	while (!b.empty()){
		ll v=b.front();
		ans[i]=v+1;

		b.pop_front();
		i++;
	}
	cout << "Yes" << '\n';
	cout << ans << '\n';
#endif
}

int main(){
#if 1
	solve();
#else
	ll t;  cin >> t;
	rep(i, 0, t-1){
		solve();
	}
#endif
	return 0;
}
