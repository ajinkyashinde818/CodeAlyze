#include <stdio.h>

int main(){
	int A,B,K;
	int cnt;
	int ans;
	
	scanf("%d %d %d",&A,&B,&K);
	
	cnt=0;
	for(int i=100;i>0;i--){
		if(A%i==0 && B%i==0)	cnt++;
		
		if(cnt==K){
			ans=i;
			break;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
