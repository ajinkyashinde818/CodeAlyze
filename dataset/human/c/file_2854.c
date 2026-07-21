#include <stdio.h>

int main(void){
	int k, s, count = 0;
	int rest, ymin, ymax;

	scanf("%d%d", &k, &s);

	for(int i=0; i <= k && i <= s; i++) {
		rest = s - i;
		ymin = rest - k;
		ymax = rest;
		if(ymin < 0)
			ymin = 0;
		if(ymax > k)
			ymax = k;
		if(ymin <= ymax)
			count += ymax - ymin + 1;
	}
	printf("%d", count);

	return 0;
}
