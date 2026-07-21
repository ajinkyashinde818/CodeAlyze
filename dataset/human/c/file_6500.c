#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, j, n, maxv=-1000000000, temp, minv;
	int *r;
	scanf("%d", &n);
	r = malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d", &r[i]);
	}
	minv=r[0];
	for(j=1;j<n;j++){
		temp=r[j]-minv;
		if(maxv<temp){
			maxv=temp;
		}
		if(minv>r[j]){
			minv=r[j];
		}
	}
	printf("%d\n", maxv);
}
