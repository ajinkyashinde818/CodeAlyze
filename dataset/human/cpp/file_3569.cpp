/*input
5
10 -4 0 -11 3
*/
#include <bits/stdc++.h>
using namespace std;
		 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<pi> vpi;
typedef vector<vpi> vpii;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<pd> vpd;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef std::string str;
typedef std::vector<str> vs;

#define x first
#define y second
#define debug(...) cout<<"["<<#__VA_ARGS__<<": "<<__VA_ARGS__<<"]\n"

const int MOD = 1000000007;
const ll INF = std::numeric_limits<ll>::max();
const int MX = 100101;
const ld PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270L;

template<typename T>
pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return pair<T, T>(a.x + b.x, a.y + b.y); }
template<typename T>
pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return pair<T, T>(a.x - b.x, a.y - b.y); }
template<typename T>
T operator*(const pair<T, T> &a, const pair<T, T> &b) { return (a.x * b.x + a.y * b.y); }
template<typename T>
T operator^(const pair<T, T> &a, const pair<T, T> &b) { return (a.x * b.y - a.y * b.x); }


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int minusai = 0;
	cin >> N;
	ll maz = MOD;
	ll sum = 0;	
	ll a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		if(a < 0){
			minusai++;
			a *= -1;
		}
		sum += a;
		maz = min(maz, a);
	}
	if(minusai & 1){
		printf("%lld\n", sum - 2*maz);
	} else{
		printf("%lld\n", sum);
	}
}

/* Look for:
* special cases (n=1?)
* overflow (ll vs int?)
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* array bounds
*/
