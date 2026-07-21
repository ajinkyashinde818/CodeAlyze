/*  /$$                                     /$$
      | $$                                    | $$
  /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$
 /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  | $$| $$$$$$$$| $$      | $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/
| $$  | $$| $$_____/| $$      | $$  | $$| $$  | $$| $$_____/| $$
|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$
 \_______/ \_______/ \_______/ \______/  \_______/ \_______/|__//$$$$$$ /$$$$$$
                                                               |______/|______/

*/
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_map>
#define fastio        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ln            cout << endl;
#define vi            vector<int>
#define vll           vector<long long>
#define sortl(vec)    sort(vec.begin(), vec.end());
#define sortr(vec)    sort(vec.rbegin(), vec.rend());
#define forn(i, x, n) for(long long i = x; i < n; i++)
#define revn(i, n, x) for(long long i = n; i >= x; i--)
#define in(vec)       for(auto &it : vec) cin >> it;
#define	out(vec)      for(auto &it : vec) cout << it << " "; ln
#define ll            long long
#define pb            emplace_back
#define mp            make_pair
#define um            unordered_map
#define pii           pair<int, int>
#define pll           pair<ll, ll>
#define f             first
#define sec           second
#define pi            3.14159265359
#define o(x)		  cout << x << endl;
#define CLOCK         cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
using namespace std;

const ll Nfact = 200005;
const ll mod = 1000000007;
const ll Nseive = 1000005;
//https://codeforces.com/blog/entry/74640?#comment-587521

vector<bool> is_prime(Nseive, true);
void seive() {
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= Nseive; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= Nseive; j += i)
				is_prime[j] = false;
		}
	}
}

ll bS(ll l, ll r, ll x, vll arr) {
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

void primeFactors(ll n) {
	while (n % 2 == 0) {
		//cout << 2 << " ";
		n = n / 2;
	}

	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			//cout << i << " ";
			n = n / i;
		}
	}

	if (n > 2)
		cout << n << " ";
}

ll power(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modulo(ll a, ll b) {
	ll c = a % b;
	return (c < 0) ? c + b : c;
}

//Use these functions below only when modulus is involved
ll mul(ll x, ll y) {
	return (x * y) % mod;
}

ll inv(ll x) {
	return power(x, mod - 2, mod);
}

ll divide(ll x, ll y)
{
	return mul(x, inv(y));
}

ll fact[Nfact];
void precalc() { // Call this once in main()
	fact[0] = 1;
	for (ll i = 1; i < Nfact; i++)
		fact[i] = mul(fact[i - 1], i);
}

ll nCr(ll n, ll k) {
	if (n < k)
		return 0;
	return divide(fact[n], mul(fact[k], fact[n - k]));
}

int main() {
// in(vec) works for size-defined type vectors

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	fastio
	ll t = 1;
	while (t--) {
		ll n;
		cin >> n;
		vll vec(n);
		in(vec)
		ll sum = 0, count = 0;
		ll mini = abs(vec[0]);
		forn(i, 0, n) {
			sum += abs(vec[i]);
			mini = min(mini, abs(vec[i]));
			if (vec[i] < 0)
				count++;
		}
		if (count & 1) {
			o(sum - 2 * mini)
		}
		else {
			o(sum)
		}
	}
	CLOCK
	return 0;
}
// Think in terms of block of minus signs. 
//If block size is even then every one can be made 
//positive in that grp in other case only on will 
//remain negative. Now we have single negative 
//elements separated by positive elements. 
//Now use the below link
//Credits: https://www.quora.com/How-do-I-solve-Flipping-Signs-on-AtCoder
