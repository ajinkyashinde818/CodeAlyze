#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);

	int n;
	scanf("%d", &n);
	vi a(n);
	bool zero = false;
	int neg = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] < 0) {
			a[i] = -a[i];
			++neg;
		}
		else if (a[i] == 0)
			zero = true;
	}

	//ll ans = 0;
	//for (int x : a) ans += x;
	ll ans = accumulate(all(a), 0LL);
	if (neg % 2 == 1 && !zero)
		ans -= 2 * (*min_element(all(a)));
	printf("%lld\n", ans);
}
