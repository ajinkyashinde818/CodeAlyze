#include<cstdio>
#include<cmath>
#include<algorithm>
#include<numeric>

using namespace std;

typedef long long ll;

int main(){
	int n; scanf("%d", &n);
	ll a[200000];
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	ll s = a[0], b = accumulate(a + 1, a + n, 0LL);
	ll res = abs(s - b);
	for(int i = 1; i < n - 1; i++){
		s += a[i]; b -= a[i];
		res = min(res, (ll)abs(s - b));
	}
	printf("%lld\n", res);
	return 0;
}
