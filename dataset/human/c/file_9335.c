#include <stdio.h>
 
int main(){
	int i,N,K;
	int cnt = 0;
	int a[100001];
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
		if(a[i]>=K) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
