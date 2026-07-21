#include<stdio.h>
long int gcd(long int num1,long int num2)
{
	long int t,r=1;
	if(num1<num2)
	{
		t = num1;
		num1 = num2;
		num2 = t;
	}
	while(r != 0)
	{
		r = num1 % num2;
		num1 = num2;
		num2 = r;
	}
	return num1;
}

int main(void)
{
	long int num1,num2;
    long int ans;
	char str[64];
	
	fgets(str,sizeof(str),stdin);
	sscanf(str,"%ld %ld",&num1,&num2);
	
	ans = num1 * num2;
	ans /= gcd(num1,num2);
	
	printf("%ld",ans);
	
	return 0;
}
