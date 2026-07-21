#include <stdio.h>

int main(void){
	int N,D,X;
	int i;
	scanf("%d",&N);
	scanf("%d",&D);
	scanf("%d",&X);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	int ans=0;
	int d;
	for(i=0;i<N;i++){//人数
		d=1;
		while(d<=D){
			ans++;
			d+=A[i];
		}
	}
	
	ans+=X;
	printf("%d",ans);
	return 0;}
