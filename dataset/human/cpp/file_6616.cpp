#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

ll N, num[2] = {}, L = 0, ans = 1;
string S;
bool isLeft[200000] = {};

ll fact(ll num) {
	if (num == 1) {
		return 1;
	}
	else {
		return (num * fact(num - 1)) % 1000000007;
	}
}

int main() {
	cin >> N;
	cin >> S;
	rep(i, sz(S)) {
		if (i % 2 == 0) {
			if (S[i] == 'W') {
				isLeft[i] = false;
			}
			else {
				isLeft[i] = true;
			}
		}
		else {
			if (S[i] == 'W') {
				isLeft[i] = true;
			}
			else {
				isLeft[i] = false;
			}
		}
		num[isLeft[i]]++;
	}
	if (num[0] != num[1] || S[0] == 'W' || S[sz(S) - 1] == 'W') {
		cout << 0 << endl;
		return 0;
	}
	rep(i, sz(S)) {
		if (isLeft[i]) {
			L++;
		}
		else {
			ans *= L;
			ans %= 1000000007;
			L--;
		}
	}
	cout << (ans* fact(N)) % 1000000007 << endl;
	return 0;
}
