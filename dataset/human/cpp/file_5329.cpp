#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
int main() {
	ll n, r;
	scanf("%lld %lld", &n, &r);
	if (n < 10) {
		ll k = 100 * (10 - n);
		printf("%lld", k + r);
	}
	else {
		printf("%lld", r);
	}
}
