#include<stdio.h>

int main(){
	long long int n, count=0;
	scanf("%lld", &n);
	if(n%2){
		printf("0");
		return 0;
	}else{
		n/=2;
		int y=5;
		while(n/y){
			count+=n/y;
			n/=5;
		}
		printf("%lld", count);
		return 0;
	}
}
