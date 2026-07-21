#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> primeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}


#define in(x) cin >> x
#define out(x) cout << x
#define outn(x) cout << x << '\n'
#define outs(x) cout << x << ' '
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
	ll n,ans=0;
	in(n);
	vll a(n);
	pair<ll, ll> tmp=make_pair(1000000001,-1);
	in(a[0]);
	rep(i, 1, n) {
		in(a[i]);
		if (a[i - 1] < 0) {
			a[i - 1] *= -1;
			a[i] *= -1;
		}
		if (tmp.first > a[i - 1]) {
			tmp.first = a[i - 1];
			tmp.second = i - 1;
		}
	}
	if (a[n - 1] < 0) {
		if (a[n - 1] * -1 > tmp.first) {
			a[n - 1] *= -1;
			a[tmp.second] *= -1;
		}
	}

	rep(i, 0, n) {
		ans += a[i];
	}
	outn(ans);
	return 0;

}
