#include<stdio.h>
int table[500000];
int prime[100000];
int main(){
	table[0]=-1;
	table[1]=-1;
	for(int i=2;i<500000;i++){
		if(table[i]!=-1){
			table[i]=1;
			for(int j=i*2;j<500000;j+=i){
				table[j]=-1;
			}
		}
	}
	int now=0;
	for(int i=0;i<500000;i++){
		if(table[i]==1)prime[now++]=i;
	}
	int a;
	while(scanf("%d",&a),a){
		long long int ret=0;
		for(int i=0;i<a;i++){
			ret+=prime[i];
		}
		printf("%lld\n",ret);
	}
}
