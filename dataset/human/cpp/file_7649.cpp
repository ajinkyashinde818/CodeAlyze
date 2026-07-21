#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
 
using namespace std;
 
const int N = 2e5 + 10;
typedef long long LL;
int a[N];
 
 
int main()
{
	int n;
	LL sum = 0;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if(n == 2){
		printf("%d\n",abs(a[1] - a[2]));
		return 0;
	}
	LL ans = 0;
	LL Min = (LL)1e18;
	for(int i = 1 ; i < n ; i++){
		ans += a[i];
		Min = min(Min , abs(ans - (sum - ans)));
	}
	printf("%lld\n",Min);
}
