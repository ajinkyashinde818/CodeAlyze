#include<stdio.h>

int main(){
	int A,B,K;
	int i,c,k=1,ans;
	scanf("%d %d %d",&A,&B,&K);
	while(A!=0){
		B=B%A;
		c=A,A=B,B=c;
	}
	for(i=c;i>=1;i--){
		if(c%i==0){
			if(k==K){
				ans=i;
				break;
			}
			k++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
