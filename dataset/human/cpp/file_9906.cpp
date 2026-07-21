#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<map>
#include <cstdint>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
using ll = long long;
using namespace std;

uintmax_t combination(int n, int r) {
	if (r * 2 > n) r = n - r;
	uintmax_t dividend = 1;
	uintmax_t divisor = 1;
	for (unsigned int i = 1; i <= r; ++i) {
		dividend *= (n - i + 1);
		divisor *= i;
	}
	return dividend / divisor;
}
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	ll devide = pow(10, 9) + 7;
	ll count = 1;
	vector<int>alpha(26);
	rep(i, n) {
		ll a = s[i];
		a -= 97;
		alpha[a]++;
	}

	rep(i, 26) {
		if (alpha[i] >= 1) {
			count *= (alpha[i] + 1);
			count %= devide;
		}
	}


	cout << count-1 << endl;

}
