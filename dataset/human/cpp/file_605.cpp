#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll MOD = (ll)pow(10.0, 9.0) + 7;
pint dx[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
char da[4] = { 'R', 'L', 'D', 'U' };
char dad[4] = { 'L', 'R', 'U', 'D' };
ll min(ll a, ll b)
{

	return (a < b) ? a : b;
}
ll max(ll a, ll b) { return (a > b) ? a : b; }

ll N;






int main() {
	ll R, G, B, N;

	cin >> R >> G >> B >> N;

	ll cnt = 0;
	for (int i = 0; i <= (N / R); i++) {
		for (int j = 0; j <= (N / G); j++) {

			if (N - R * i - G * j >= 0 && (N - R * i - G * j) % B == 0)
				cnt += 1;
		}
	}



	cout << cnt << endl;
	return 0;

}
