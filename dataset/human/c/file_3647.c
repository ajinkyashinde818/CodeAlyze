#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max(a, b)	(((a) > (b)) ? (a) : (b))		/* ２個の値の最大値 */
#define min(a, b)	(((a) < (b)) ? (a) : (b))		/* ２個の値の最小値 */
#define ENTER		printf("\n")					/* 改行プリント */
int DBG = 1;										/* デバッグプリント 提出時は0 */

long gcd(long m, long n);							/* 最大公約数 */
long lcm(long m, long n);							/* 最小公倍数 */

/* 最大公約数 */
long gcd(long m, long n) {
	long temp;
	while (m % n != 0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}

/* 最小公倍数 */
long lcm(long m, long n) {
	return m*n/gcd(m,n);
}
/* main *************************************************************/
int main()
{
	int		a,b;
	long    ans;

	
	scanf("%d",&a);
	scanf("%d",&b);
	
	ans = lcm( (long)a, (long)b);
	
	printf("%lld\n",ans);


	return 0;
}
