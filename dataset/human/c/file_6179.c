#include <stdio.h>

int main(void) {
	long i, n, val, tmin, trange, tmp;
	
	scanf("%ld\n", &n);
	scanf("%ld\n", &tmin);
	scanf("%ld\n", &tmp);
	trange = tmp - tmin;
	if(tmin > tmp) {
		tmin = tmp;
	}
	for(i=2;i<n;i++) {
		scanf("%ld\n", &val);
		if(tmin > val) {
			tmin = val;
		} else if(trange < val-tmin) {
			trange = val - tmin;
		}
	}

	printf("%ld\n", trange);

	return 0;
}
