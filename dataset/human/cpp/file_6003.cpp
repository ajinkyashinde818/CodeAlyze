#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

class RMQ {
#define RMQ_MAX ((1ll<<60)-1)
public:
	RMQ(int n) {
		_n=1;
		while(_n<n) _n*=2;
		_dat.resize(2*_n-1);
		for(int i=0;i<2*_n-1;++i) _dat[i]=0;
	}
	int size() {
		return _n;
	}
	void update(int k,long long a) {
		k+=_n-1;
		_dat[k]=a;
		while(k>0) {
			k=(k-1)/2;
			_dat[k]=max(_dat[k*2+1],_dat[k*2+2]);
		}
	}
	// return the minimum number in [a,b)
	// external call should be written like query(a,b,0,0,_n)
	ll query(int a,int b,int k=0,int l=0,int r=-1) {
		if(r==-1) r=_n;
		if(r<=a||b<=l) return 0;
		if(a<=l&&r<=b) return _dat[k];
		else {
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr);
		}
	}
private:
	int _n;
	vector<ll> _dat;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,c;
	cin>>n>>c;
	vector<P> z(n);
	REP(i,n) cin>>z[i].first>>z[i].second;
	sort(ALL(z));
	ll ans=0;
	ll buf=0;
	ll pos=0;
	REP(i,n) {
		buf-=z[i].first-pos;
		pos=z[i].first;
		buf+=z[i].second;
		ans=max(ans,buf);
	}
	RMQ rmq(n+10);
	buf=0;
	REP(i,n) {
		buf+=z[n-1-i].second;
		rmq.update(n-1-i,buf-(c-z[n-1-i].first));
	}
	buf=0;
	REP(i,n) {
		buf+=z[i].second;
		ans=max(ans,buf-2*z[i].first+rmq.query(i+1,n+5));
	}
	vector<P> w(n);
	REP(i,n) w[i]=z[n-1-i];
	REP(i,n) w[i].first=c-w[i].first;
	buf=0;
	pos=0;
	REP(i,n) {
		buf-=w[i].first-pos;
		pos=w[i].first;
		buf+=w[i].second;
		ans=max(ans,buf);
	}
	buf=0;
	REP(i,n) {
		buf+=w[n-1-i].second;
		rmq.update(n-1-i,buf-(c-w[n-1-i].first));
	}
	buf=0;
	REP(i,n) {
		buf+=w[i].second;
		ans=max(ans,buf-2*w[i].first+rmq.query(i+1,n+5));
	}
	cout<<ans<<endl;
}
