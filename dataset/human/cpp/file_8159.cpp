#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
 
long a[1000005],b[1000005],c[1000005];
 
int main()
{
	int i,n,k;
	while(~scanf("%d",&n)){
		long t = 0,sum = 0,qs = 0;
		for(i = 1; i <= n; i++) {
			scanf("%ld",&a[i]);
			sum += a[i];
		}
		for(i = n; i > 1; i--){
			sum -= a[i];
			qs += a[i];
			b[++t] = abs(sum-qs);
		}
		sort(b+1,b+1+t);
		printf("%ld\n",b[1]);
	}
	return 0;
}
