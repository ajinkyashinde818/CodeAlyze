#include <stdio.h>

int IsPrime(int n){
	int i;
	if(n==1) return 0;
	if(n==2){
		return 1;
	}else if(n%2==0){
		return 0;
	}
	for(i=3;i*i<=n;i+=2){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int n , p[10001] , count = 2 , sum_p[10001];
	p[1] = 2;
	for(n=3;count<=10000;n+=2){
		if(IsPrime(n)){
			p[count] = n;
			count++;
		}
	}
	sum_p[1] = 2;
	for(n=1;n<10000;n++){
		sum_p[n+1] = sum_p[n] + p[n+1];
	}
	while(1){
		scanf("%d" , &n);
		if(n==0) break;
		printf("%d\n" , sum_p[n]);
	}
	return 0;
}
