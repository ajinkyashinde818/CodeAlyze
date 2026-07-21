#include<stdio.h>

int main(){
	
	int N,K,h[100010],i,ans=0;
	
	scanf("%d %d",&N,&K);
	
	for(i=1;i<=N;i++){
		scanf("%d",&h[i]);
		if(h[i]>=K){
			ans++;
		}
	}
	
	printf("%d\n",ans);
	
	
	return 0;
}
