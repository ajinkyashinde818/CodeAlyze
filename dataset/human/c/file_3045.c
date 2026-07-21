#include<stdio.h>
int main()
{
	int whole;
	int number;
	int num[200000]; 
	scanf("%d%d",&whole,&number);
	for(int n=0;n<number;n++)
		{scanf("%d",&num[n]);}
	int result=0;
	for(int n=1;n<number;n++)
		{if(result<num[n]-num[n-1])
			{
			result=num[n]-num[n-1];}
		}
	if(result>whole-num[number-1]+num[0])
		result=whole-result;
	else
		result=num[number-1]-num[0];
	printf("%d",result);
}
