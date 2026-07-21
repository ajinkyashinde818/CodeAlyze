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
	int		a,b,c,i,j,k,n,m,x,y,ans=0;
	int		h;
	
	scanf("%d %d", &n, &k);
	for(i=1;i<=n;i++) {
		scanf("%d", &h);
		if (h >= k) ans++;
	}

	printf("%d\n",ans);


	return 0;
}
