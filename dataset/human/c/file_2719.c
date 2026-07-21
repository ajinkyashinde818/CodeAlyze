#include<stdio.h>

int main(){
	
	int K,S,i,j,ans=0;
	scanf("%d %d",&K,&S);
	
	for(i=0;i<=K;i++){
		for(j=0;j<=K;j++){
			if(0<=S-i-j&&S-i-j<=K){
				ans++;
			}
		}
	}
	
	printf("\n%d\n",ans);
	
	return 0;
}
