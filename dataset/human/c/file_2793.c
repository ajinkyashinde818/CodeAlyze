#include<stdio.h>

int min(int x,int y){
	if(x<y)return x;
	return y;
}

int main(){
	int K,S,ans=0;
	scanf("%d%d",&K,&S);
	for(int x=0;x<=min(K,S);x++)
		for(int y=0;y<=min(K,S);y++)if(S-x-y>=0 && S-x-y<=K)ans++;
			
	printf("%d\n",ans);
	return 0;
}
