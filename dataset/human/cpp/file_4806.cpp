#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using intpair=pair<int,int>;
using llpair=pair<ll,ll>;
using intq=queue<int>;
using llq=queue<ll>;
using intvec=vector<int>;
using llvec=vector<ll>;
using llmat=vector<vector<ll>>;
#define PI 3.141592653589793
#define INTINF 1<<30
#define LLINF 1LL<<60
#define pushb push_back
#define all(name) name.begin(),name.end()
#define llmattp(name,a,b,num) name(a,vector<ll>(b,num))
#define ABS(x) ( (x)>0 ? (x) : -(x) )
#define gsort(vbeg,vend) sort(vbeg,vend,greater<>())

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll a, ll b) { //最大公約数
	if(a==0||b==0) return 0;
	if(a<b) swap(a,b);
	ll tmp = a%b;
	while(tmp!=0) {
		a = b;
		b = tmp;
		tmp = a%b;
	}
	return b;
}

ll modpow(ll a, ll ex, ll p) { //繰り返し二乗法
	if(ex==1) return a%p;
	if(ex%2) return a%p*modpow(a,ex-1,p)%p;
	ll tmp=modpow(a,ex/2,p)%p;
	return tmp*tmp%p;
}

ll factorial(ll x) { //階乗
	ll f=1;
	for(ll i=2; i<=x; i++) {
		f*=i;
	}
	return f;
}

ll nPr(ll n, ll r) {
	ll result=1;
	for(ll i=r+1; i<=n; i++) result*=i;
	return result;
}

ll nCr(ll n, ll r) {
	if (n == r) { return 1; }
	if (r > n) { return 0; }

	if (r > n / 2) { r = n - r; }

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return (ll)result;
}

ll LowerBinarySearch(llvec array, ll key, ll max, ll min) { //にぶたんlower
	if(max>min) {
		return -1LL;
	} else {
		ll mid = max + (min-max)/2;
		if(array[mid]>key) {
			return LowerBinarySearch(array,key,max,mid-1);
		} if(array[mid]<key) {
			return LowerBinarySearch(array,key,mid+1,min);
		} else {
			return mid;
		}
	}
}

ll GreaterBinarySearch(llvec array, ll key, ll max, ll min) { //にぶたんgreater
	if(max>min) {
		return -1LL;
	} else {
		ll mid = max + (min-max)/2;
		if(array[mid]<key) {
			return GreaterBinarySearch(array,key,max,mid-1);
		} if(array[mid]>key) {
			return GreaterBinarySearch(array,key,mid+1,min);
		} else {
			return mid;
		}
	}
}

int DigitNum(ll n) { //桁数
	int digit=0;
	ll wari=1LL;
	while(n/wari) {
		digit++;
		wari*=10;
	}
	return digit;
}

bool IsPrime(ll num) { //素数判定
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (ll i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

vector<ll> Divisor(ll x) { // 約数列挙
	vector<ll> result;
	ll i=1LL;
	for( ; i*i<x; i++) {
		if(x%i) continue;
		result.push_back(i);
		result.push_back(x/i);
	}
	if(i*i==x&&x%i==0)
		result.push_back(i);
	
	sort(result.begin(),result.end());
	return result;
}

vector<llpair> PrimeFact(ll x) { // 素因数分解 {素因数,指数}
	vector<llpair> result;
	ll ex=0LL;
	if(x%2==0) {
		while(x%2==0) {
			x/=2;
			ex++;
		}
		result.push_back({2,ex});
	}

	for(ll i=3LL; i*i<=x; i+=2) {
		if(x%i) continue;

		ex=0LL;
		while(x%i==0) {
			x/=i;
			ex++;
		}
		result.push_back({i,ex});
	}

	if(x!=1) result.push_back({x,1});

	return result;
}

bool Palind(string s) { //回文判定
	return s == string(s.rbegin(), s.rend());
}

struct Vertex{
	vector<int> eg;
	vector<ll> egcost;
	ll cost;
	bool conf;
};

int sv[26],tv[26];

int main() {
	int N, R; cin>>N>>R;

	if(N<10) {
		cout<<R+100*(10-N)<<endl;
	}
	else
	 cout<<R<<endl;
}
