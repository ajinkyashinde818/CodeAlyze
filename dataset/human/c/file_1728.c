#include <stdio.h>

int main(void) {
	int n; scanf("%d",&n);
	int ary[n+1]; for(int i=1; i<=n; i++) scanf("%d",&ary[i]);
	int bry[n+1]; for(int i=1; i<=n; i++) scanf("%d",&bry[i]);
	int cry[n+1]; for(int i=1; i<=n; i++) scanf("%d",&cry[i]);
	int ex_dish = n;
	int satis = 0;
	for(int i=1; i<=n; i++) {
		satis += bry[ary[i]];
		if (ary[i] - 1 == ex_dish) {
			satis += cry[ex_dish];
		}
		ex_dish = ary[i];
	}
	printf("%d",satis);
	
	return 0;
}
