#include <stdio.h>
int main(){
	int t,n,j,maxv,minv,R[200000];
	scanf("%d",&n);
	for(t=0;t<n;t++)
		scanf("%d",&R[t]);
	maxv=-2000000000;
	minv=R[0];
	for(j=1;j<n;j++){
		if(maxv<R[j]-minv)
			maxv=R[j]-minv;
		if(minv>R[j])
			minv=R[j];
	}
	printf("%d\n",maxv);
	return 0;
}
