#include <stdio.h>

int main(){
	int n, r0, r, d;

	scanf("%d", &n);
	scanf("%d", &r0);

	int maxv = -1000000000;
	int minv = r0;

	for( int i = 1; i < n; i++){
		scanf("%d", &r);
		d = r - minv;
		maxv = (d > maxv ? d : maxv);
		minv = (r < minv ? r : minv);
	}

	printf("%d\n", maxv);

	return 0;
}
