#include <stdio.h>
#include <math.h>
int PrimeNumbers(int num);
int main(void){
	int sum,num,i;
	char str[100];
	for( ; ; ){
		scanf("%d",&num);
		if(num==0)
			break;
		sum=PrimeNumbers(num);
		printf("%d\n",sum);
	}
	return 0;
}

int PrimeNumbers(int num){
	int c,j,b=1,sum=0,cnt=0;
	start:;
	if(cnt==num)
		return sum;
	b++; 
	if(b==2){
		sum+=b;
		cnt++;
		goto start;
	}
	if(b%2==0)
		goto start;
	c = sqrt(b);
	for(j=3;j<=c;j+=2){
		if(b%j==0){
			goto start;
		}
	}
	sum+=b;
	cnt++;
	goto start;
}
