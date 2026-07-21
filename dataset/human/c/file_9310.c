#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, k, i, co=0;
	scanf("%d%d", &n, &k);
	int *h;
	h=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d", &h[i]);
	for(i=0;i<n;i++){
		if(h[i]>=k) co++;
	}
	printf("%d", co);
	free(h);
	return 0;
}
