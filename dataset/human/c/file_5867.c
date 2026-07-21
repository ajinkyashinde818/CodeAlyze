#include <stdio.h>

int main(void) {
	int n, i;
	long int r[200000];
	scanf("%d", &n);
	for(i = 0; n > i; i++){
		scanf("%ld", &r[i]);
	}
	int small = r[0]+1, maxp = 0;
	long int ans = r[1] - r[0];
	for(i = 0; n-1 > i; i++){
		int j;
		if(small > r[i]){
		small = r[i];
		for(j = i+1; n > j; j++){
			if(ans < r[j] - r[i]) ans = r[j] - r[i];
		}
		}
	}
	printf("%ld\n", ans);
	return 0;
}
