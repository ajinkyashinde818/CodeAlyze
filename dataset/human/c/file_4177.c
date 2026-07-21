#include<stdio.h>

int main(){
	int a,b,i,c=0,k;
	scanf("%d%d%d",&a,&b,&k);
	for(i=100;i>=1;i--){
		if(a%i==0&&b%i==0)c++;
		if(c==k){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
