#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>

int main(){
	int *R,i,n,pr,vMin=0;
	
	scanf("%d", &n);
	R = (int *)malloc(sizeof(int)*n);

	
	for (i = n; i >0; --i) 	scanf("%d", R + n-i);
	vMin = R[0];
	pr =R[1]-R[0];
	for (i = 1; i < n; i++) {
		if (R[i] - vMin > pr) pr = *(R + i) - vMin;
		if (R[i] < vMin)vMin = *(R + i);
	}
	printf("%d\n", pr);
	return 0;
}
