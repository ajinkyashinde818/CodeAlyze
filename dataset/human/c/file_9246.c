#include <stdio.h>
#include <math.h>
static int h[100010];
int 
main(){
	long int N,i;
	long int cnt=0;
	int K;
	scanf("%ld %d",&N,&K);

	for(i=0;i<N;i++){
		scanf("%d",&h[i]);
	}
	
	for(i=0;i<N;i++){
		if(h[i]>=K)cnt++;

	}
	printf("%ld\n",cnt);
 return 0;
}
