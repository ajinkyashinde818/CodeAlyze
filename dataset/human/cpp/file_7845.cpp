#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n;
LL a[200005];
LL l[200005], r[200005], ans = 10000000000;
int main()
{
	scanf("%lld",&n);
	for(LL i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		l[i] = l[i - 1] + a[i];
	}
	for(LL i = n; i >= 1; i--){
		r[i] = r[i + 1] + a[i];
	}
	for(LL i = 1; i < n; i++){
		ans = min(ans,abs(l[i] - r[i + 1]));
	}
	printf("%lld\n",ans);
	return 0;
}
