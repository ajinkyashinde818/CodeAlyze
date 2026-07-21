#include <stdio.h>

int minnum(int a,int b){
	if(a > b)return b;
	else return a;
}

int main(void){
	int a,b,k;
	int res[100];
	int c=0;
	scanf("%d %d %d",&a ,&b ,&k);
	int min = minnum(a,b);
	for(int i=1;i<=min;i++){
		if(a % i == 0 && b % i == 0){
			res[++c] = i;
		}
	}
	printf("%d\n",res[c-k+1]);
	return 0;
}
