#include<stdio.h>
int prime[11111],ptr=0;
void prime_number(void){
	int i,j,flag;
	prime[ptr++]=2;prime[ptr++]=3;
	for(i=5;ptr<=10474;i+=2){
		flag=0;
		for(j=1;prime[j]*prime[j]<=i;j++){
			if(i%prime[j]==0){flag=1;break;}
		}
		if(!flag){prime[ptr++]=i;}
	}
}
int main(void){
	int i,j,n,k,ans;
	prime_number();
	while(1){
		scanf("%d",&n);
		ans=0;ptr=0;
		if(n==0)break;
		for(i=0;i<n;i++){ans+=prime[i];}
		printf("%d\n",ans);
	}
	return 0;
}
