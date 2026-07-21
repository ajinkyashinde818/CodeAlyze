#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using dbl = double;
using pii = pair<int, int>;
using pl4 = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpl4 = vector<pl4>;
using vvpl4 = vector<vpl4>;
using vd = vector<dbl>;
using vvd = vector<vd>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define sz size()
#define bgn begin()
#define en end()
#define asn assign
#define emp empty()
#define fr front()
#define bk back()
#define clr clear()
#define ins insert
#define ers erase
#define res resize
#define tp top()

#define p_q priority_queue

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rFOR(i,a,b) for(int i=(b);i>=(a);i--)
#define REP(i,a) FOR((i),0,(a)-1)
#define REP0(i,a) FOR((i),0,(a))
#define REP1(i,a) FOR((i),1,(a))
#define rREP(i,a) rFOR((i),0,(a)-1)
#define rREP0(i,a) rFOR((i),0,(a))
#define rREP1(i,a) rFOR((i),1,(a))
#define ROR(v,i) for(auto &(i):(v))
#define IOTA(a,n) iota((a).bgn,(a).en,(n))
#define SORT(a) sort((a).bgn,(a).en)
#define rSORT(a) sort((a).rbegin(),(a).rend())
#define UNIQUE(a) (a).erase(unique((a).bgn,(a).en),(a).en)
#define PREVP(a) prev_permutation((a).bgn,(a).en)
#define NEXTP(a) next_permutation((a).bgn,(a).en)
#define BINS(a,b) binary_search((a).bgn,(a).en,(b))
#define LOWB(a,b) (lower_bound((a).bgn,(a).en,(b))-(a).bgn)
#define UPB(a,b) (upper_bound((a).bgn,(a).en,(b))-(a).bgn)
#define CNT(a,b) count((a).bgn,(a).en,b)
#define SUM(a) accumulate((a).bgn,(a).en,0)
#define REV(a) reverse((a).bgn,(a).en)
#define REGS(a,b) regex_search((a),regex(b))
#define REGM(a,b) regex_match((a),regex(b))
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;
#define Imp(a) cout <<((a)?"Possible":"Impossible")<<endl;
#define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<endl;
#define say(a) cout <<(a);
#define sal(a) cout <<(a)<<endl;
#define sak cout <<endl;
#define sas cout <<" ";
#define sat cout <<"\t";
#define dbg(a) cout <<(#a)<<": "<<(a)<<endl;
#define c2l(a) ((ll)(a-48))
#define a2l(a) ((ll)(a-97))
#define A2l(a) ((ll)(a-65))
#define l2c(a) ((char)(a+48))
#define l2a(a) ((char)(a+97))
#define l2A(a) ((char)(a+65))
#define DigN2(a) ((llabs(a)==0)?(1):((ll)(log2(double(llabs(a))))+1))
#define DigN10(a) ((llabs(a)==0)?(1):((ll)(log10(double(llabs(a))))+1))
#define Dig2(a,b) (((a)>>(b))&1)
#define Dig10(a,b) (ll)(((a)/((ll)(pow(10.0,(double)(b)))))%10)
#define Pow2(a) (1<<(a))
#define Pow10(a) ((ll)(pow(10.0,double(a))))
#define LSB(a) ((a)&(-(a)))
#define llin(a) ll (a);cin >>(a);
#define stin(a) string (a);cin >>(a);
#define vin(v) ROR((v),(i)){cin >>(i);};
#define vllin(v,N) vll (v)((N));vin(v);
#define vsin(v,N) vs (v)((N));vin(v);
#define rdn(a,b) ((a)/(b))
#define rou(a,b) ((((double(a)/double(b))-((a)/(b)))<0.5)?((a)/(b)):(((a)/(b))+1))
#define rup(a,b) ((((a)%(b))==0)?((a)/(b)):(((a)/(b))+1))
#define min(a,b) ((a<b)?(a):(b))
#define max(a,b) ((a>b)?(a):(b))
#define powll(a,b) (ll)(pow((double)(a),(double)(b)))
#define Triangle(x1,y1,x2,y2,x3,y3) (((x1)-(x2))*((y1)-(y3))-((x1)-(x3))*((y1)-(y2)))

#define int ll

const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = 9007199254740881;
const ll INF = 1LL << 60;
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class BIT {

public:
	vll d;
	vll v;
	ll size;
	BIT(ll sizeget) {
		size = sizeget;
		d.asn(size + 1, 0);
		v.asn(size, 0);
	}
	BIT(vll cpyvec) {
		copy(cpyvec);
	}
	void add(ll index, ll num) {
//		if (index < 0) return false;
//		if (index >= size) return false;
		v[index] += num;
		index++;
		while (index <= size) {
			d[index] += num;
			index += LSB(index);
		}
//		return true;
		return;
	}
	ll csum(ll index = INF) {
		index++;
		index = min(index, size);
		ll ans = 0;
		while (index) {
			ans += d[index];
			index -= LSB(index);
		}
		return ans;
	}
	ll sum(ll a, ll b) {
		if (a > b) return 0;
		if (a == 0) return csum(b);
		return csum(b) - csum(a - 1);
	}
	void copy(vll cpyvec) {
		size = cpyvec.sz;
		d.asn(size + 1, 0);
		v.asn(size, 0);
		REP(i, size) add(i, cpyvec[i]);
	}

};

class UFT {

public:
	ll size;
	ll mode;
	vll root;
	vll rank;
	UFT(ll sizeget, ll modeget = 0){
		size = sizeget;
		mode = modeget;
		root.res(size, 0);
		if (!mode) rank.res(size, 0);
		IOTA(root, 0);
	}
	ll find(ll x) {
		return root[x] == x ? x : root[x] = find(root[x]);
	}
	bool same(ll x, ll y) {
		return find(x) == find(y);
	}
	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (mode) root[y] = x;
		else {
			if (rank[x] < rank[y]) {
				root[x] = y;
			}
			else {
				root[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
};

/*class SegT {

public:

	ll size;
	ll mode;
	vll v;
	SegT(ll sizeget, ll modeget = 0) {
		size = sizeget;
		mode = modeget;
		init();
	}
	SegT(vll cpyvec, ll modeget = 0) {
		size = DigN2(cpyvec.sz);
		if (cpyvec.sz == Pow2(size - 1)) size--;
		mode = modeget;
		init();
		copy(cpyvec);
	}
	void init() {
		v.asn(Pow2(size + 1) - 1, initv());
	}
	void copy(vll cpyvec) {
		REP(i, min(cpyvec.sz, Pow2(size))) set(i, cpyvec[i]);
	}
	ll initv() {
		ll ans = 0;
		switch (mode) {
		case 0:
			ans = 0;
			break;
		case 1:
			ans = INF;
			break;
		case 2:
			ans = 0;
			break;
		}
		return ans;
	}
	ll calc(ll a, ll b) {
		ll ans = initv();
		switch (mode) {
		case 0:
			ans = a + b;
			break;
		case 1:
			ans = min(a, b);
			break;
		case 2:
			ans = max(a, b);
			break;
		}
		return ans;
	}
	ll i2v(ll i) const{
		return Pow2(size) + i - 1;
	}
	ll top(ll i) const{
		return (i - 1) / 2;
	}
	pl4 bot(ll i) const{
		return mp(2 * i + 1, 2 * i + 2);
	}
	void set(ll i, ll x) {
		i = i2v(i);
		v[i] = x;
		while (i > 0) {
			i = top(i);
			v[i] = calc(v[bot(i).fi], v[bot(i).se]);
		}
	}
	ll operator[](const ll &i) const {
		return v[i2v(i)];
	}
	ll query(ll a, ll b, ll i, ll l, ll r) {
		if (r <= a || b <= l) return initv();
		if (a <= l && r <= b) return v[i];
		else {
			ll vl = query(a, b, bot(i).fi, l, (l + r / 2));
			ll vr = query(a, b, bot(i).se, (l + r / 2), r);
			return calc(vl, vr);
		}
	}
	ll que(ll a, ll b) {
		return query(a, b + 1, 0, 0, Pow2(size));
	}

};*/

/*class Graph {

};*/

ll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a%b); }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

pl4 Bezout(ll a, ll b) {
	if (b != 0) {
		pl4 xy;
		xy = Bezout(b, a%b);
		return mp(xy.se, xy.fi - ((a / b)*xy.se));
	}
	if (b == 0) {
		return mp(1, 0);
	}
}
pl4 Bez(ll a, ll b, ll c) {
	pl4 xy;
	ll x, y, z, gc;
	xy = Bezout(a, b);
	gc = gcd(a, b);
	if (c%gc != 0) return mp(-1, -1);
	x = xy.fi*(c / gc); y = xy.se*(c / gc);
	if (x < 0) z = rup(-x, (b / gc));
	if (x >= 0) z = -x / (b / gc);
	x += z * (b / gc);
	y -= z * (a / gc);
	return mp(x, y);
}

void salv(vll v) {
	say("{");
	FOR(i, 0, v.sz - 1) {
		say(v[i]);
		if (i != v.sz - 1) say(",");
	}
	sal("}")
}

ll DigS10(ll n) {
	ll m = 0;
	FOR(i, 0, DigN10(n) - 1) {
		m += (ll)((llabs(n) % (ll)(pow(10.0, (double)(i + 1)))) / (ll)(pow(10.0, (double)i)));
	}
	return m;
}

ll isP(ll n) {
	if (n <= 1) return 0;
	FOR(i, 2, (ll)sqrt(n)) {
		if (n%i == 0) return 0;
	}
	return 1;
}

vll FactM(1, 1);
vll FactMI(1, 1);

ll PowM(ll a, ll b) {
	ll ans = 1, x = (a%MOD);
	FOR(i, 0, DigN2(b) - 1) {
		if (Dig2(b, i) == 1) ans = (ans*x) % MOD;
		if (i != (DigN2(b) - 1)) x = (x*x) % MOD;
	}
	return ans;
}

ll Mod(ll a) {
	a %= MOD;
	a = (a + MOD) % MOD;
	return a;
}

ll InvM(ll a) {
	a = Mod(a);
	a = PowM(a, MOD - 2);
	return a;
}

void CFactM(ll n) {
	if (FactM.sz <= n) {
		FOR(i, FactM.sz, n) {
			FactM.pb((FactM[i - 1] * (i%MOD)) % MOD);
		}
	}
	return;
}

void CFactMI(ll n) {
	CFactM(n);
	if (FactMI.sz < (n + 1)) FactMI.res(n + 1, -1);
	if (FactMI[n] == -1) FactMI[n] = PowM(FactM[n], MOD - 2);
	rFOR(i, 1, n - 1) {
		if (FactMI[i] != -1) break;
		FactMI[i] = ((FactMI[i + 1] * ((i + 1) % MOD)) % MOD);
	}
	return;
}

ll CombM(ll n, ll k) {
	if ((n < 0) || (k < 0)) return 0;
	if (n < k) return 0;
	if (n + 1 > FactMI.sz) CFactMI(n);
	return ((((FactMI[k] * FactMI[n - k]) % MOD)*FactM[n]) % MOD);
}

ll LIS(vll v, ll m = 0) {

	if (v.sz > 0) {
		ll ans = 0;
		vll dp(v.sz, INF);
		FOR(i, 0, v.sz - 1) {
			dp[m ? UPB(dp, v[i]) : LOWB(dp, v[i])] = v[i];
		}
		FOR(i, 0, v.sz - 1) {
			if (dp[i] == INF) break;
			ans++;
		}
		return ans;
	}
	else {
		return 0;
	}

}

void cmprs(vll& v) {
	if (v.sz == 0) return;
	vll vv(v);
	IOTA(vv, 0);
	sort(vv.bgn, vv.en, [&](ll v1, ll v2) {return v[v1] < v[v2]; });
	IOTA(v, 0);
	sort(v.bgn, v.en, [&](ll v1, ll v2) {return vv[v1] < vv[v2]; });
	return;
}

ll BblCnt(vll v) {
	cmprs(v);
	BIT b(v.sz);
	ll ans = 0;
	REP(i, v.sz) {
		ans += (i - b.sum(0, v[i]));
		b.add(v[i], 1);
	}
	return ans;
}

/*
std::cout << std::fixed;
std::cout << std::setprecision(2) << 3.141; // "3.14"
std::cout << std::setprecision(2) << 3.0;   // "3.00"
*/

signed main() {

	llin(N);
	vll a(1, 0);
	ll aa = 1;
	while (1) {
		a.pb(a.bk + aa);
		aa++;
		if (a.bk > 200000) break;
	}
	ll n = -1;
	REP(i, a.sz) {
		if (N == a[i]) {
			n = i + 1;
			break;
		}
	}
	Yn(n != -1);
	if (n != -1) {
		vvll an(n);
		ll uwa = 1;
		FOR(i, 0, n - 2) {
			FOR(j, i + 1, n - 1) {
				an[i].pb(uwa);
				an[j].pb(uwa);
				uwa++;
			}
		}
		sal(n);
		REP(i, n) {
			say(an[i].sz);
			REP(j, an[i].sz) {
				sas;
				say(an[i][j]);
			}
			sak;
		}
	}

}
