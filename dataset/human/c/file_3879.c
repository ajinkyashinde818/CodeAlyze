#include <stdio.h>
int gcd(int a, int b){
	return a%b?gcd(b,a%b):b;
}
int main(){
	int A,B,K;
	scanf("%d %d %d",&A,&B,&K);
	int g=gcd(A,B),i,cnt;
	for(i=1,cnt=0;cnt<K;i++) if(g%i==0) cnt++;
	i--;
	printf("%d",g/i); 
}
