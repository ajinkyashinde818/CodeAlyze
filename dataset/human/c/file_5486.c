#include <stdio.h>
#define NN 999999
int main(){
	int i,j,n,sum;
	bool prime[NN];
	for(i=0;i<NN;i++) prime[i]=true;
	while(1){
		sum=0;n=0;
		scanf("%d",&n);
		if(!n) break;
		for(i=2;i<NN;i++){
			for(j=i*2;j<NN;j=j+i) prime[j]=false;
		}
		for(i=2,j=0;j<n;i++){
			if(prime[i]==true){
				sum+=i;
				j++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
