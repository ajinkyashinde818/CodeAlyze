#include<stdio.h>

int main(){
	
	int N,a[100010],i,botan=1,ans=0;
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<=N;i++){
		botan=a[botan];
		ans++;
		
		if(botan==2){
			printf("\n%d\n",ans);
			return 0;
		}
	}
	
	printf("\n-1\n");
	
	return 0;
}
