#include<algorithm>//everybody dies in their nightmares
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<unordered_set>
#include<unordered_map>
#define f(i,a,b) for(register int i=a;i<=b;++i)
#define ff(i,a,b) for(register int i=a;i>=b;--i)
#define debug(x) cerr << #x << " : " << x << " " << endl
using namespace std;
typedef long long ll;
const ll mod = 1000;
ll oula(ll x) { ll res = x;f(i, 2, x / i) { if (x % i == 0) { res = res / i * (i - 1);while (x % i == 0) x /= i; } }if (x > 1) res = res / x * (x - 1);return res; }
ll quickmod(ll a, ll n) { ll s = 1;while (n) { if (n & 1) { s = s * a % mod; }a = (a*a) % mod;n = n / 2; }return s; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
void ex_gcd(ll a, ll b, ll &x, ll &y, ll &d) { if (!b) { d = a, x = 1, y = 0; } else { ex_gcd(b, a % b, y, x, d);y -= x * (a / b); } }
ll inv(ll t, ll p) { ll d, x, y;ex_gcd(t, p, x, y, d);return d == 1 ? (x % p + p) % p : -1; }
bool isPrime(long long x) { if (x <= 1)return false;if (x == 2)return true;if (x % 2 == 0)return false;long long i, m;m = sqrt(x);f(i, 2, m) { if (x % i == 0)return false; }return true; }

const int N = 2e5 + 5;

int t;

int main()
{

	//cin >> t;
	int n, dr;
	while (cin >> n >> dr)
	{
		if (n >= 10)
			cout << dr << endl;
		else cout << dr + 100 * (10 - n) << endl;
	}
	return 0;
}
