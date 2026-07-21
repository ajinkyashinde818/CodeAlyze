#include <stdio.h>
int main(void){
	int a,b,k;
	int n = 0;
	int i;
	int y[100]={};
	scanf("%d%d%d",&a,&b,&k);
	for(i=1;i<=100;i++){
		if(a%i==0 && b%i==0){
			y[n] = i;
			n++;
		}
	}
	printf("%d",y[n-k]);
	return 0;
}
