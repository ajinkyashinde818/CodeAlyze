#include <stdio.h>

int main(void){
	long int a;
	while(1){
		int sum=0;
	scanf("%ld",&a);
	if(a==0)
		break;
	while(a!=1){
		if(a%2==0)
			a/=2;
		else{
			a*=3;
			a++;
		}
		sum++;
	}
	printf("%d\n",sum);
	}
	return 0;
}
