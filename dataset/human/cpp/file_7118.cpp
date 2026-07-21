#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
long long a[1000000],b[1000000],c[1000000];
int main ()
{
	int n,i,j,k,x,y;
	long long sum;
	scanf("%d", &n);
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		sum = sum + a[i];
		b[i] = sum;
	}
	for (i = 1; i <= n-1; i++)
	{
		c[i] = abs(b[i] - (sum - b[i]));
	}
	sort(c+1,c+n);
	printf("%lld",c[1]);
}
