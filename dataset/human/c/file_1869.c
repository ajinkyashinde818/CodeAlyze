#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max(a, b)	(((a) > (b)) ? (a) : (b))		/* ２個の値の最大値 */
#define min(a, b)	(((a) < (b)) ? (a) : (b))		/* ２個の値の最小値 */
#define ENTER		printf("\n")					/* 改行プリント */
int DBG = 1;										/* デバッグプリント 提出時は0 */
/* main *************************************************************/
int main()
{
	int		a[30],b,c[30],i,j,k,n,m,x,y,ans = 0;
	char	str[256];
	
	scanf("%d", &n);
	a[0] = -1;
	for(i=1;i<=n;i++) scanf("%d", &a[i]);
	for(i=1;i<=n;i++) {
		scanf("%d", &b);
		ans += b;
	}
	for(i=1;i<n;i++) scanf("%d", &c[i]);
	
	for(i=1;i<=n;i++) {
		if (a[i] == (a[i-1] + 1)) {
			ans += c[a[i-1]];
		}
	}

	printf("%d\n",ans);


	return 0;
}
