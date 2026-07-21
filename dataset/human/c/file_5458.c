#include <stdio.h>
#define c(a,b) ((a)>(b)?(a):(b))
int main (void){
	int W,H,N,n,m,i,p,q,d=0;
	scanf("%d %d %d",&W,&H,&N);
	scanf("%d %d",&n,&m);
	for(i=1;i<N;i++,n=p,m=q){
		scanf("%d %d",&p,&q);
		if((p-n)*(q-m)>0)d+=c(abs(p-n),abs(q-m));
		else d+=abs(p-n)+abs(q-m);
	}
	printf("%d\n",d);
	return 0;
}
