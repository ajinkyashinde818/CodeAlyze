#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;
LL a[200010];
LL sum, ans, d;
int main() {
	d = 1LL << 60;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	for(int i = 1; i <= n - 1; i++){
		ans += a[i];
		sum -= a[i];
		d = min(d, abs(sum - ans));
	}
	printf("%lld\n", d);
}
