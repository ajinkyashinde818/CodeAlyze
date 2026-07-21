#include <stdio.h>
int main()
{
	int k, s;
	int xmin, xmax, x;
	int ymin, ymax;
	int res = 0;
	scanf("%d %d", &k, &s);
	xmin = s - 2 * k;
	if(xmin < 0) xmin = 0;
	xmax = k;
	if(s < xmax) xmax = s;
	for(x = xmin; x <= xmax; x++){
		ymin = s - x - k;
		if(ymin < 0) ymin = 0;
		ymax = k;
		if(s - x < k) ymax = s - x;
		res += ymax - ymin + 1;
	}
	printf("%d\n", res);
	return 0;
}
