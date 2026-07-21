#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
#include <complex>
#include <numeric>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<ll> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

typedef ll SegT;
static const SegT defvalue = 0LL;
class SegTree{
	private:
		vector<SegT> val;
		int n;
	public:
		SegTree(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n, defvalue);
		}
		void update(int i,SegT a){
			i+=n-1;
			val[i]=a;
			while(i>0){
				i=(i-1)/2;
				val[i]=max(val[i*2+1],val[i*2+2]);
			}
		}
		SegT query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return defvalue;
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};

int main(void){
	int n;
	ll c;
	cin >> n >> c;
	vi x(n), v(n), x2(n), v2(n);
	SegTree st_p(n), st_n(n);
	REP(i, n){
		cin >> x[i] >> v[i];
		x2[i] = c - x[i];
		v2[i] = v[i];
	}
	ll res = 0;
	REP(i, n){
		res += v[i];
		st_p.update(i, res - x[i]);
	}
	res = 0;
	RREP(i, n){
		res += v2[i];
		st_n.update(i, res - x2[i]);
	}
	
	REP(i, n-1) v[i+1] += v[i];
	RREP(i, n-1) v2[i] += v2[i+1];
	ll ans = 0;
	ans = max(ans, st_n.query(0, n));
	ans = max(ans, st_p.query(0, n));

	//cout << "positive route" << endl;
	REP(i, n){
		ll res = v[i] - 2 * x[i];
		res += st_n.query(i + 1, n);
		//cout << "i: " << i << " " << res << endl;
		//cout << v[i] - 2 * x[i] << endl;
		//cout << st_n.query(i + 1, n) << endl;
		ans = max(ans, res);
	}
	//cout << "negative route" << endl;
	RREP(i, n){
		ll res = v2[i] - 2 * x2[i];
		res += st_p.query(0, i);
		//cout << "i: " << i << " " << res << endl;
		//cout << v2[i] - 2 * x2[i] << endl;
		//cout << st_n.query(i + 1, n) << endl;
		ans = max(ans, res);
	}
	cout << ans << endl;
}
