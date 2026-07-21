#include <stdio.h>

int main(void)
{
	int i, n, max, rmin, r0, rt;
	scanf("%d",&n);
	scanf("%d",&r0);
	scanf("%d",&rt);
	max = rt - r0;
	if(r0 < rt) {
		rmin = r0;
	} else {
		rmin = rt;
	}
	for(i=2; i<n; i++) {
		scanf("%d",&rt);
		if(rt-rmin > max) {
			max = rt - rmin;
		}
		if(rmin > rt) {
			rmin = rt;
		}
	}
	printf("%d\n",max);
	return 0;
}
