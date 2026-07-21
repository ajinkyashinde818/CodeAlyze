#include <stdio.h>
int max (int a,int b){return a>b ? a:b;}
int min (int a,int b){return a<b ? a:b;}
#define MAX 200000
int main(void) {
	int R[MAX],r,i,maxv,minv;
	scanf("%d",&r);
	for(i = 0; i < r; i++){scanf("%d",&R[i]);}
	maxv = -2000000000;
	minv = R[0];
	for(i = 1; i < r; i++){
		maxv = max(maxv,R[i]-minv);
		minv = min(minv,R[i]);
	}
	printf("%d\n",maxv);
	return 0;
}
