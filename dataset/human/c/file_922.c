#include <stdio.h>
int main(void){
	int N,friend[100010]={0},a,b,i,ans;
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		scanf("%d %d",&a,&b);
		friend[a]+=1;
		friend[b+1]-=1;
	}
	
	for(i=0;i<=N+1;i++){
		friend[i]+=friend[i-1];	
		if(i-1<=friend[i])
			ans=i-1;
	}
	
	printf("%d\n",ans);
	
	return 0;
}
