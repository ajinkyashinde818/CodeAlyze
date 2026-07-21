#include<stdio.h>

int main(){
	int n, Rt[199999], i, j,  maxv, minv;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d",&Rt[i]);
	}
	minv = Rt[0];
	maxv = Rt[1] - Rt[0];
	for (j = 1; j < n; j++) {
		if ((Rt[j] - minv) > maxv) {
			maxv = Rt[j] - minv;
		}
		if (Rt[j] < minv) {
			minv = Rt[j];
		}
	}
	printf("%d\n", maxv);
	
	return 0;

}
