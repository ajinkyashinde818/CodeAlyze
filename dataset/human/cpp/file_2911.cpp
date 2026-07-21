#include <algorithm>
#include <cstdio>

using namespace std ;

typedef long long LL ;
const int N=1e6+10 ;

LL f[N][2] ;
LL a[N] ;
int n ;

int main ()
{
	int i ;
	scanf("%d",&n);
	for ( i=1 ; i<=n ; i++ )
		scanf("%lld",a+i);
	f[2][0]=a[1]+a[2],
	f[2][1]=-f[2][0];
	for ( i=3 ; i<=n ; i++ )
		f[i][0]=max(f[i-1][0]+a[i],f[i-1][1]+a[i]),
		f[i][1]=max(f[i-1][0]-2*a[i-1]-a[i],f[i-1][1]+2*a[i-1]-a[i]);
	printf("%lld\n",max(f[n][0],f[n][1]));
	return 0 ;
}
